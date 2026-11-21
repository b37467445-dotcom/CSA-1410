#include <stdio.h>
#include <string.h>

int main()
{
    char line[100];

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    if (line[0] == '/' && line[1] == '/')
    {
        printf("It is a comment.\n");
    }
    else
    {
        printf("It is not a comment.\n");
    }

    return 0;
}