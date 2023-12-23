#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "inventory_system.h"

enum option {
    ADD_ITEM = 1,
    REMOVE_ITEM,
    LIST_ITEMS,
    EXIT
};

void clear() 
{
    system("clear");
}

void menu_info()
{
    printf("======== Menu ========\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. List items\n");
    printf("4. Exit\n");
    printf("======================\n");
}

void menu_add_item()

{
    struct item item;
    printf("Name: ");
    scanf("%19s", item.name);
    printf("Quantity: ");
    scanf("%d", &item.quantity);
    printf("Price: ");
    scanf("%f", &item.price);
    printf("Weight or volume: ");
    scanf("%d", &item.measure.weight);

    save_item(item);

}

void menu_init()
{
    int choice = 0;
    while (choice != EXIT) {
        clear();
        menu_info();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case ADD_ITEM:
                menu_add_item();
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
