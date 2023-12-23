#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory_system.h"



void inventory_system_init()
{
    printf("Inventory system initialized\n");
}

void save_item (struct item item)
{
    FILE *fp;
    fp = fopen("inventory.txt", "a");
    fprintf(fp, "%s;%d;%f;%d\n", item.name, item.quantity, item.price, item.measure.weight);
    fclose(fp);
}

struct item* read_items(int *count)
{
    FILE *fp;
    fp = fopen("inventory.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        *count = 0;
        return NULL;
    }
    *count = 0;
    char c;

    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {
            *count = *count + 1;
        }
    }

    rewind(fp);

    struct item *items = malloc(*count * sizeof(struct item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        *count = 0;
        fclose(fp);
        return NULL;
    }
    char name[20];
    int quantity;
    float price;
    int weight;
    int index = 0;
    while (fscanf(fp, "%19[^;];%d;%f;%d\n", name, &quantity, &price, &weight) != EOF) {
        strcpy(items[index].name, name);
        items[index].quantity = quantity;
        items[index].price = price;
        items[index].measure.weight = weight;

        index++;
    }
    fclose(fp);

    return items;
}