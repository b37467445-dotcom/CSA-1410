#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[30];
    int address;
};

struct Symbol table[100];
int count = 0;

int search(char name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0)
            return i;
    }

    return -1;
}

void insert() {
    char name[30];
    int address;

    printf("Enter symbol name: ");
    scanf("%s", name);

    if (search(name) != -1) {
        printf("Symbol already exists!\n");
        return;
    }

    printf("Enter address: ");
    scanf("%d", &address);

    strcpy(table[count].name, name);
    table[count].address = address;
    count++;

    printf("Symbol inserted successfully.\n");
}

void display() {
    int i;

    printf("\nSymbol Table\n");
    printf("-------------------\n");
    printf("Name\tAddress\n");

    for (i = 0; i < count; i++)
        printf("%s\t%d\n", table[i].name, table[i].address);
}

void searchSymbol() {
    char name[30];
    int pos;

    printf("Enter symbol to search: ");
    scanf("%s", name);

    pos = search(name);

    if (pos == -1)
        printf("Symbol not found.\n");
    else
        printf("Symbol found: %s, Address: %d\n",
               table[pos].name, table[pos].address);
}

void modify() {
    char name[30];
    int pos, address;

    printf("Enter symbol to modify: ");
    scanf("%s", name);

    pos = search(name);

    if (pos == -1) {
        printf("Symbol not found.\n");
        return;
    }

    printf("Enter new address: ");
    scanf("%d", &address);

    table[pos].address = address;

    printf("Symbol modified successfully.\n");
}

int main() {
    int choice;

    do {
        printf("\n1.Insert\n2.Display\n3.Search\n4.Modify\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: searchSymbol(); break;
            case 4: modify(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}