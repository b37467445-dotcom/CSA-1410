#include <stdio.h>
#include <string.h>

int main() {
    char expression[100];
    char result[20];
    char operand1[20], operand2[20];
    char op;
    char temp[20];

    int i, j, tempCount = 1;

    printf("Enter expression (example: out=a+b+c-d): ");
    scanf("%s", expression);

    i = 0;

    while (expression[i] != '=')
        i++;

    strncpy(result, expression, i);
    result[i] = '\0';

    i++;

    j = 0;

    while (expression[i] != '+' &&
           expression[i] != '-' &&
           expression[i] != '\0') {
        operand1[j++] = expression[i++];
    }

    operand1[j] = '\0';

    printf("\nThree Address Code:\n");

    while (expression[i] != '\0') {
        op = expression[i++];
        j = 0;

        while (expression[i] != '+' &&
               expression[i] != '-' &&
               expression[i] != '\0') {
            operand2[j++] = expression[i++];
        }

        operand2[j] = '\0';

        sprintf(temp, "t%d", tempCount);

        printf("%s = %s %c %s\n",
               temp, operand1, op, operand2);

        strcpy(operand1, temp);
        tempCount++;
    }

    printf("%s = %s\n", result, operand1);

    return 0;
}