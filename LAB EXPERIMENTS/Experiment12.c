#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int pos = 0;

int E();
int EP();
int T();
int TP();
int F();

int E() {
    if (T())
        return EP();

    return 0;
}

int EP() {
    if (input[pos] == '+') {
        pos++;

        if (T())
            return EP();

        return 0;
    }

    return 1;
}

int T() {
    if (F())
        return TP();

    return 0;
}

int TP() {
    if (input[pos] == '*') {
        pos++;

        if (F())
            return TP();

        return 0;
    }

    return 1;
}

int F() {
    if (input[pos] == '(') {
        pos++;

        if (E() && input[pos] == ')') {
            pos++;
            return 1;
        }

        return 0;
    }

    if (isalpha(input[pos])) {
        pos++;
        return 1;
    }

    return 0;
}

int main() {
    printf("Enter expression: ");
    scanf("%s", input);

    if (E() && input[pos] == '\0')
        printf("String is accepted.\n");
    else
        printf("String is not accepted.\n");

    return 0;
}