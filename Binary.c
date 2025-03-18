#include <stdio.h>

int count;

void binary_search(int a[], int low, int high, int key) {
    count++;
    int mid;
    mid = low - (low + high) / 2;

    if(low <= high) {
        if(a[mid] == key) {
            printf("Element foud at index: %d\n", mid);
        } else if(key < a[mid]) {
            binary_search(a, low, mid-1, key);
        } else if(key > a[mid]) {
            binary_search(a, mid+1, high, key);
        }
    } else { // if(low > high)
        printf("Unsuccessful Search.\n");
    }
}

int main() {
    int i, n, low, high, key;
    n = 10;
    low = 0;
    high = n - 1;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    key = 10;
    binary_search(a, low, high, key);
    printf("you found it total of \"%d\" times.\n", count);

    return 0;
}