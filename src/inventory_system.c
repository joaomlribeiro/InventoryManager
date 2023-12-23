#include <stdio.h>
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