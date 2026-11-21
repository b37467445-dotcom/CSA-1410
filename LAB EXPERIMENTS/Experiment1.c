#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[100];
    int i = 0;

    printf("Enter an expression: ");
    scanf("%s", input);

    printf("\nTokens:\n");

    while (input[i] != '\0')
    {
        if (isalpha(input[i]))
        {
            printf("Identifier: ");

            while (isalnum(input[i]))
            {
                printf("%c", input[i]);
                i++;
            }

            printf("\n");
        }
        else if (isdigit(input[i]))
        {
            printf("Constant: ");

            while (isdigit(input[i]))
            {
                printf("%c", input[i]);
                i++;
            }

            printf("\n");
        }
        else
        {
            printf("Operator: %c\n", input[i]);
            i++;
        }
    }

    return 0;
}