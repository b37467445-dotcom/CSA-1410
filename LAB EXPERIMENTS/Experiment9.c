#include <stdio.h>
#include <string.h>

int main() {
    char lhs, alpha[50], beta[50];
    int n, i, j;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        char p[100];
        printf("Enter production (example L->L,S|S): ");
        scanf("%s", p);

        lhs = p[0];

        if (p[3] == lhs) {
            printf("\nLeft recursion found in %s\n", p);

            j = 4;
            int k = 0;

            while (p[j] != '|' && p[j] != '\0')
                alpha[k++] = p[j++];

            alpha[k] = '\0';

            j++;
            k = 0;

            while (p[j] != '\0')
                beta[k++] = p[j++];

            beta[k] = '\0';

            printf("Grammar after eliminating left recursion:\n");
            printf("%c->%s%c'\n", lhs, beta, lhs);
            printf("%c'->%s%c'|epsilon\n", lhs, alpha, lhs);
        }
        else {
            printf("\n%s has no immediate left recursion.\n", p);
        }
    }

    return 0;
}