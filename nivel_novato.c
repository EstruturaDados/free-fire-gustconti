#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10
#define NAME_SIZE 50
#define TYPE_SIZE 30

typedef struct {
    char name[NAME_SIZE];
    char type[TYPE_SIZE];
    int amount;
    int active;
} Item;

void addItem(Item inventory[]) {
    int freeIndex = -1;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i].active == 0) {
            freeIndex = i;
            break;
        }
    }

    if (freeIndex == -1) {
        printf("\nInventário cheio! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n--- Adicionar Item ---\n");

    getchar(); 

    printf("Nome do item: ");
    fgets(inventory[freeIndex].name, NAME_SIZE, stdin);
    inventory[freeIndex].name[strcspn(inventory[freeIndex].name, "\n")] = '\0';

    printf("Tipo do item: ");
    fgets(inventory[freeIndex].type, TYPE_SIZE, stdin);
    inventory[freeIndex].type[strcspn(inventory[freeIndex].type, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &inventory[freeIndex].amount);

    inventory[freeIndex].active = 1;

    printf("Item adicionado com sucesso!\n");
}

void removeItem(Item inventory[]) {
    char searchName[NAME_SIZE];
    int found = 0;

    getchar();

    printf("\n--- Remover Item ---\n");
    printf("Digite o nome do item que deseja remover: ");
    fgets(searchName, NAME_SIZE, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i].active == 1 && strcmp(inventory[i].name, searchName) == 0) {
            inventory[i].active = 0;
            found = 1;
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!found) {
        printf("Item não encontrado.\n");
    }
}

void listItems(Item inventory[]) {
    int empty = 1;

    printf("\n--- Itens no Inventário ---\n");

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i].active == 1) {
            printf("Item %d:\n", i + 1);
            printf("  Nome: %s\n", inventory[i].name);
            printf("  Tipo: %s\n", inventory[i].type);
            printf("  Quantidade: %d\n\n", inventory[i].amount);
            empty = 0;
        }
    }

    if (empty) {
        printf("O inventário está vazio.\n");
    }
}

int main() {
    Item inventory[MAX_ITEMS] = {0};
    int option;

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item pelo nome\n");
        printf("3 - Listar itens cadastrados\n");
        printf("0 - Sair\n");
        printf("==========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addItem(inventory);
                break;

            case 2:
                removeItem(inventory);
                break;

            case 3:
                listItems(inventory);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }

    } while (option != 0);

    return 0;
}