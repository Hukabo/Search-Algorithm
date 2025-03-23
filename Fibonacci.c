#include <stdio.h>

int min(int, int);
int fibonacci_search(int[], int, int);

int min(int a, int b) {
    return (a > b) ? b : a;
}

int fibonacci_search(int arr[], int n, int key) {
    int offset = -1;
    int Fm2 = 0;
    int Fm1 = 1;
    int Fm = Fm2 + Fm1;

    while(Fm < n) {
        Fm2 = Fm1; // 5
        Fm1 = Fm; // 8
        Fm = Fm2 + Fm1; // 13
    }

    while(Fm > 1) {
        int i = min(offset + Fm2, n - 1);
        if(arr[i] == key){
            return i;
        } else if(arr[i] < key) {
            Fm = Fm1;
            Fm1 = Fm2;
            Fm2 = Fm - Fm1;
            offset = i;
        } else if(arr[i] > key) {
            Fm = Fm2;
            Fm1 = Fm1 - Fm2;
            Fm2 = Fm - Fm1;
        }
    }
    if(Fm1 && arr[offset + 1] == key) {
        return offset + 1;
    }
    return -1;
}

int main() {
    int i, key, index;
    int arr[10] = {6, 11, 19, 24, 33, 54, 67, 81, 94, 99};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Array elements are: ");
    for(int j = 0; j < len; j++) {
        printf(" %d",arr[j]);
    }

    for(i = 0; i < len; i++) {
        key = arr[i];
        printf("\nThe element to be searched: %d", key);
        index = fibonacci_search(arr, len, key);

        if(index >= 0)
            printf("\nThe element is found at index %d",index);
        else
            printf("\nUnsuccessful Search");
    }
    

    return 0;
}