#include <stdio.h>
#include <string.h>

char trailing[3][20];

int add(int set, char ch) {
    int i;

    for (i = 0; trailing[set][i] != '\0'; i++) {
        if (trailing[set][i] == ch)
            return 0;
    }

    i = strlen(trailing[set]);
    trailing[set][i] = ch;
    trailing[set][i + 1] = '\0';

    return 1;
}

int main() {
    int changed, i;

    char productions[][10] = {
        "E+T",
        "T",
        "T*F",
        "F",
        "(E)",
        "i"
    };

    printf("Grammar:\n");
    printf("E->E+T|T\n");
    printf("T->T*F|F\n");
    printf("F->(E)|i\n");

    do {
        changed = 0;

        for (i = 0; i < 6; i++) {
            char lhs, rhs[10];

            if (i < 2)
                lhs = 'E';
            else if (i < 4)
                lhs = 'T';
            else
                lhs = 'F';

            strcpy(rhs, productions[i]);

            int set = lhs - 'E';
            int len = strlen(rhs);

            char last = rhs[len - 1];

            if (last == 'E' || last == 'T' || last == 'F') {
                int source = last - 'E';

                for (int j = 0; trailing[source][j] != '\0'; j++)
                    changed |= add(set, trailing[source][j]);

                if (len >= 2 &&
                    (rhs[len - 2] == '+' || rhs[len - 2] == '*')) {
                    changed |= add(set, rhs[len - 2]);
                }
            }
            else {
                changed |= add(set, last);
            }
        }

    } while (changed);

    printf("\nTRAILING(E) = { ");
    for (i = 0; trailing[0][i] != '\0'; i++)
        printf("%c ", trailing[0][i]);

    printf("}\n");

    printf("TRAILING(T) = { ");
    for (i = 0; trailing[1][i] != '\0'; i++)
        printf("%c ", trailing[1][i]);

    printf("}\n");

    printf("TRAILING(F) = { ");
    for (i = 0; trailing[2][i] != '\0'; i++)
        printf("%c ", trailing[2][i]);

    printf("}\n");

    return 0;
}