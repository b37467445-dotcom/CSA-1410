#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[200];
    int i = 0;

    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    printf("\nTokens:\n");

    while (input[i] != '\0')
    {
        if (isspace(input[i]))
        {
            i++;
        }
        else if (input[i] == '/' && input[i + 1] == '/')
        {
            break;
        }
        else if (isalpha(input[i]))
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