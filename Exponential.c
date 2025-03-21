#include <stdio.h>
#include <math.h>

int exponential_search(int[], int, int);
int binary_search(int[], int, int, int);

int main() {
    int i, len, key, index;
    int arr[10] = {6, 11, 19, 25, 33, 53, 67, 81, 94, 99};

    printf("Arra elements are: ");
    len = sizeof(arr) / sizeof(arr[0]);

    for(int j = 0; j < len; j++) {
        printf(" %d", arr[j]);
    }

    for(i = 0; i < len; i++) {

        key = arr[i];
        printf("\nThe element to be searched: %d", key);

        index = exponential_search(arr, len, key);

        if(index >= 0) {
            printf("\nThe element is found at %d", index);
        } else {
            printf("\nUnsuccessful Search");
    }
    }
    

    return 0;
}

int exponential_search(int arr[], int n, int key) {
    
    if(arr[0] == key)
        return 0;
    
    int i = 1; // 지수 초기값

    while(arr[i] <= key && i < n) // key값이 속해있는 block 찾기
        i = i * 2;

    return binary_search(arr, i/2, (i < n ? i : n - 1), key);
}

int binary_search(int arr[], int low, int high, int key) {

    int mid = low + (high - low) / 2;

    if(low <= high) {
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            return binary_search(arr, mid + 1, high, key);
        else
            return binary_search(arr, low, mid - 1, key);
    }

    return -1;
}