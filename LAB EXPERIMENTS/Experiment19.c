#include <stdio.h>
#include <string.h>

char leading[3][20];

int add(int set, char ch) {
    int i;

    for (i = 0; leading[set][i] != '\0'; i++) {
        if (leading[set][i] == ch)
            return 0;
    }

    i = strlen(leading[set]);
    leading[set][i] = ch;
    leading[set][i + 1] = '\0';

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

            if (rhs[0] == 'E' || rhs[0] == 'T' ||
                rhs[0] == 'F') {

                int source = rhs[0] - 'E';

                for (int j = 0; leading[source][j] != '\0'; j++)
                    changed |= add(set, leading[source][j]);

                if (rhs[1] == '+' || rhs[1] == '*')
                    changed |= add(set, rhs[1]);
            }
            else {
                changed |= add(set, rhs[0]);
            }
        }

    } while (changed);

    printf("\nLEADING(E) = { ");
    for (i = 0; leading[0][i] != '\0'; i++)
        printf("%c ", leading[0][i]);

    printf("}\n");

    printf("LEADING(T) = { ");
    for (i = 0; leading[1][i] != '\0'; i++)
        printf("%c ", leading[1][i]);

    printf("}\n");

    printf("LEADING(F) = { ");
    for (i = 0; leading[2][i] != '\0'; i++)
        printf("%c ", leading[2][i]);

    printf("}\n");

    return 0;
}