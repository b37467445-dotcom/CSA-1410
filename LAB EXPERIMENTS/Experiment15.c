#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int E();
int T();
int F();

int E() {
    if (!T())
        return 0;

    while (input[pos] == '+') {
        pos++;

        if (!T())
            return 0;
    }

    return 1;
}

int T() {
    if (!F())
        return 0;

    while (input[pos] == '*') {
        pos++;

        if (!F())
            return 0;
    }

    return 1;
}

int F() {
    if (input[pos] == 'i') {
        pos++;
        return 1;
    }

    if (input[pos] == '(') {
        pos++;

        if (E() && input[pos] == ')') {
            pos++;
            return 1;
        }
    }

    return 0;
}

int main() {
    printf("Grammar:\n");
    printf("E->E+T|T\n");
    printf("T->T*F|F\n");
    printf("F->(E)|i\n");

    printf("\nEnter expression (use i for identifier): ");
    scanf("%s", input);

    if (E() && input[pos] == '\0')
        printf("Expression Accepted.\n");
    else
        printf("Expression Rejected.\n");

    return 0;
}