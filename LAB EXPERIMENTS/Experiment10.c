#include <stdio.h>
#include <string.h>

int main() {
    char production[100];
    char first[50], second[50];
    char common[50], remainder1[50], remainder2[50];

    int i = 0, j = 0, k = 0, pos = 0;

    printf("Enter two productions separated by |: ");
    scanf("%s", production);

    while (production[i] != '|') {
        first[j++] = production[i++];
    }
    first[j] = '\0';

    i++;
    j = 0;

    while (production[i] != '\0') {
        second[j++] = production[i++];
    }
    second[j] = '\0';

    while (first[k] != '\0' &&
           second[k] != '\0' &&
           first[k] == second[k]) {
        common[k] = first[k];
        k++;
    }

    common[k] = '\0';
    pos = k;

    strcpy(remainder1, first + pos);
    strcpy(remainder2, second + pos);

    printf("\nLeft Factored Grammar:\n");
    printf("S->%sX\n", common);
    printf("X->%s|%s\n", remainder1, remainder2);

    return 0;
}