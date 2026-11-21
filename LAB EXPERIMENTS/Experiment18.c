#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char code[100];
    char lhs, op, arg1, arg2;

    printf("Enter number of intermediate codes: ");
    scanf("%d", &n);

    printf("\nEnter three address codes (example: a=b+c):\n");

    for (i = 0; i < n; i++) {
        scanf("%s", code);

        lhs = code[0];
        arg1 = code[2];
        op = code[3];
        arg2 = code[4];

        printf("\nGenerated code for %s:\n", code);

        printf("MOV %c, R%d\n", arg1, i);

        switch (op) {
            case '+':
                printf("ADD %c, R%d\n", arg2, i);
                break;

            case '-':
                printf("SUB %c, R%d\n", arg2, i);
                break;

            case '*':
                printf("MUL %c, R%d\n", arg2, i);
                break;

            case '/':
                printf("DIV %c, R%d\n", arg2, i);
                break;

            default:
                printf("Invalid operator\n");
                continue;
        }

        printf("MOV R%d, %c\n", i, lhs);
    }

    return 0;
}