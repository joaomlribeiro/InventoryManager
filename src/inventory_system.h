#ifndef INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_H 

union measures {
    int weight;
    double volume;
};

struct item {
    char name[20];
    int quantity;
    float price;
    union measures measure;

};

void inventory_system_init();
void save_item (struct item item);

#endif // INVENTORY_SYSTEM_H
