#include <stdio.h>
#include <string.h>
#include "menu.h"

enum option {
    ADD_ITEM = 1,
    REMOVE_ITEM,
    LIST_ITEMS,
    EXIT
};

void menu_info()
{
    printf("======== Menu ========\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. List items\n");
    printf("4. Exit\n");
    printf("======================\n");
}
void menu_init()
{
    int choice = 0;
    while (choice != EXIT) {
        menu_info();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case ADD_ITEM:
                printf("Add item\n");
                break;
            case REMOVE_ITEM:
                printf("Remove item\n");
                break;
            case LIST_ITEMS:
                printf("List items\n");
                break;
            case EXIT:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
