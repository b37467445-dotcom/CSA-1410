#include <stdio.h>
#include <string.h>
#include <ctype.h>

char productions[20][20];
char first[26][20];
char follow[26][20];

int n;

void add(char set[], char ch)
{
    int i;

    for (i = 0; set[i] != '\0'; i++)
    {
        if (set[i] == ch)
            return;
    }

    set[i] = ch;
    set[i + 1] = '\0';
}

int contains(char set[], char ch)
{
    int i;

    for (i = 0; set[i] != '\0'; i++)
    {
        if (set[i] == ch)
            return 1;
    }

    return 0;
}

/* Calculate FIRST of a non-terminal */
void findFirst(char ch)
{
    int i, j;
    char lhs;
    char rhs[20];

    if (!isupper(ch))
    {
        add(first[ch - 'A'], ch);
        return;
    }

    for (i = 0; i < n; i++)
    {
        lhs = productions[i][0];

        if (lhs == ch)
        {
            strcpy(rhs, productions[i] + 2);

            if (rhs[0] == '$')
            {
                add(first[ch - 'A'], '$');
                continue;
            }

            for (j = 0; rhs[j] != '\0'; j++)
            {
                char symbol = rhs[j];

                if (!isupper(symbol))
                {
                    add(first[ch - 'A'], symbol);
                    break;
                }

                findFirst(symbol);

                int k;
                for (k = 0; first[symbol - 'A'][k] != '\0'; k++)
                {
                    if (first[symbol - 'A'][k] != '$')
                    {
                        add(first[ch - 'A'],
                            first[symbol - 'A'][k]);
                    }
                }

                if (!contains(first[symbol - 'A'], '$'))
                    break;

                if (rhs[j + 1] == '\0')
                    add(first[ch - 'A'], '$');
            }
        }
    }
}

/* Calculate FIRST of a string */
void firstOfString(char str[], char result[])
{
    int i, j;
    result[0] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (!isupper(ch))
        {
            add(result, ch);
            return;
        }

        findFirst(ch);

        for (j = 0; first[ch - 'A'][j] != '\0'; j++)
        {
            if (first[ch - 'A'][j] != '$')
                add(result, first[ch - 'A'][j]);
        }

        if (!contains(first[ch - 'A'], '$'))
            return;
    }

    add(result, '$');
}

/* Calculate FOLLOW sets */
void findFollow()
{
    int i, j, k, changed;
    char lhs, rhs[20], result[20];

    /* Start symbol gets $ */
    add(follow[productions[0][0] - 'A'], '$');

    do
    {
        changed = 0;

        for (i = 0; i < n; i++)
        {
            lhs = productions[i][0];
            strcpy(rhs, productions[i] + 2);

            for (j = 0; rhs[j] != '\0'; j++)
            {
                if (isupper(rhs[j]))
                {
                    char suffix[20];

                    strcpy(suffix, rhs + j + 1);
                    firstOfString(suffix, result);

                    for (k = 0; result[k] != '\0'; k++)
                    {
                        if (result[k] != '$')
                        {
                            int oldLength =
                                strlen(follow[rhs[j] - 'A']);

                            add(follow[rhs[j] - 'A'], result[k]);

                            if (strlen(follow[rhs[j] - 'A'])
                                > oldLength)
                                changed = 1;
                        }
                    }

                    /* If suffix is nullable, add FOLLOW(lhs) */
                    if (contains(result, '$'))
                    {
                        for (k = 0;
                             follow[lhs - 'A'][k] != '\0';
                             k++)
                        {
                            int oldLength =
                                strlen(follow[rhs[j] - 'A']);

                            add(follow[rhs[j] - 'A'],
                                follow[lhs - 'A'][k]);

                            if (strlen(follow[rhs[j] - 'A'])
                                > oldLength)
                                changed = 1;
                        }
                    }
                }
            }
        }

    } while (changed);
}

int main()
{
    int i, j;
    char ch;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use $ for epsilon):\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s", productions[i]);
    }

    /* Calculate FIRST sets */
    for (i = 0; i < n; i++)
    {
        findFirst(productions[i][0]);
    }

    /* Calculate FOLLOW sets */
    findFollow();

    printf("\nFOLLOW Sets:\n");

    for (i = 0; i < n; i++)
    {
        ch = productions[i][0];

        /* Print each non-terminal only once */
        int alreadyPrinted = 0;

        for (j = 0; j < i; j++)
        {
            if (productions[j][0] == ch)
                alreadyPrinted = 1;
        }

        if (!alreadyPrinted)
        {
            printf("FOLLOW(%c) = { ", ch);

            for (j = 0; follow[ch - 'A'][j] != '\0'; j++)
            {
                printf("%c ", follow[ch - 'A'][j]);
            }

            printf("}\n");
        }
    }

    return 0;
}