#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, countA = 0, countB = 0, flag = 1;

    printf("Grammar: S->aS | Sb | ab\n");
    printf("Enter string: ");
    scanf("%s", str);

    i = 0;

    while (str[i] == 'a') {
        countA++;
        i++;
    }

    while (str[i] == 'b') {
        countB++;
        i++;
    }

    if (str[i] != '\0')
        flag = 0;

    if (countA >= 1 && countB >= 1 && flag == 1)
        printf("String accepted.\n");
    else
        printf("String rejected.\n");

    return 0;
}