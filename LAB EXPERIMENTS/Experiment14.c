#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void reduce() {
    if (stack[top] == 'a' || stack[top] == 'b') {
        stack[top] = 'E';
        stack[top + 1] = '\0';
        printf("Reduce: E->a/b\n");
    }

    if (top >= 2) {
        if (stack[top - 2] == 'E' &&
            (stack[top - 1] == '+' ||
             stack[top - 1] == '*' ||
             stack[top - 1] == '/') &&
            stack[top] == 'E') {

            char op = stack[top - 1];

            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';

            printf("Reduce: E->E%cE\n", op);
        }
    }
}

int main() {
    char input[100];
    int i;

    printf("Enter expression: ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    for (i = 0; input[i] != '\0'; i++) {
        push(input[i]);

        printf("%s\t%s\tShift %c\n",
               stack, input + i + 1, input[i]);

        reduce();
    }

    while (top >= 2) {
        int oldTop = top;
        reduce();

        if (top == oldTop)
            break;
    }

    if (strcmp(stack, "E") == 0)
        printf("\nString Accepted.\n");
    else
        printf("\nString Rejected.\n");

    return 0;
}