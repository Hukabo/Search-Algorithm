#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 20

struct DataItem {
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
    return key % SIZE;
}

struct DataItem* search(int key) {
    // get the hash
    int hashIndex = hashCode(key);

    // move in array until an empty
    while(hashArray[hashIndex] != NULL) {

        if(hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];
        
        // go to next cell
        hashIndex++;

        // warp around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(int key, int data) {

    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
    int len = sizeof(hashArray) / sizeof(hashArray[0]);


    if(item == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
    } else if(len >= SIZE - 1) {
        printf("HashTable is full.\n");
    }

    item->key = key;
    item->data = data;

    // get the hash
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        
        // go to next cell
        hashIndex++;

        // warp arount the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
    int key = item->key;

    // get the hash
    int hashIndex = hashCode(key);

    // move in arry until an empty
    while(hashArray[hashIndex] != NULL) {

        if(hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex];

            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            
            return temp;
        }
        // go to next cell
        hashIndex++;

        // wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display() {

    int i;

    for(i = 0; i < SIZE; i++) {
        if(hashArray[i] != NULL)
            printf("(%d, %d) ", hashArray[i]->key, hashArray[i]->data);
    }

    printf("\n");
}

int main() {
    dummyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    dummyItem->key = -1;
    dummyItem->data = -1;
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    printf("Insertion done: \n");
    printf("Contents of Hash Table: ");
    display();
    int ele = 12;
    printf("The element to be searched: %d", ele);
    item = search(ele);
    if(item != NULL) {
        printf("\nElement found: %d\n", item->key);
    } else {
        printf("\nElement not found\n");
    }
    delete(item);
    printf("Hash Table contents after deletion: ");
    display();

    return 0;
}