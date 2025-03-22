#include <stdio.h>
#define MAX 10

int list[MAX] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int search_count = 0;

int inpolation_search(int lo, int hi, int key) {

    int mid;

    if(lo <= hi) {
        mid = lo + (((hi - lo) * (key - list[lo])) / (list[hi] - list[lo]));
        search_count++;

        if(list[mid] == key) {
            return mid;
        } else {
            if(key > list[mid]) {
                return inpolation_search(mid+1, hi, key);
            } else if(key < list[mid]) {
                return inpolation_search(lo, mid-1, key);
            }
        }
    }

    return -1;
}

int main() {

    int key = 1;
    int index = inpolation_search(0, MAX-1, key);

    if(index >= 0) {
        printf("The data of index is: %d\nYou found it total of %d times.\n", index, search_count);
    } else {
        printf("The data is not exist in the array.\n");
    }
    

    return 0;
}