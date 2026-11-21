#include <stdio.h>

int main()
{
    char text[500];
    int characters = 0, words = 0, lines = 0;
    int i = 0, inWord = 0;

    printf("Enter text:\n");
    fgets(text, sizeof(text), stdin);

    while (text[i] != '\0')
    {
        characters++;

        if (text[i] == '\n')
        {
            lines++;
        }

        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }

        i++;
    }

    printf("\nCharacters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}