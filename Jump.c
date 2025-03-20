#include <stdio.h>
#include <math.h>

int jump_search(int[], int, int);

int main() {
    int i, key, index;
    int arr[18] = {0,6, 12, 14, 19, 22, 48, 66, 79, 88, 104, 126, 150, 200, 201, 223, 241, 267};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Array elements(%d) are : ", len);

    for(int j = 0; j < len; j++) {
        printf(" %d", arr[j]);
    }

    for(i = 0; i < len; i++) {
        key = arr[i];
        printf("\nThe element to be searched: %d\n", key);
        index = jump_search(arr, len, key);
 
        if(index >= 0)
            printf("The element is found at position %d\n", index+1);
        else
            printf("Unsucessful Search.\n");

    }
    
    return 0;
}

int jump_search(int arr[], int n, int key) {
    /* i = start of block, j = variable of for(),
        m = variable for check range of array,
        k = block size 
     */
    int i, j, m, k, remain;
    i = 0;
    m = sqrt(n);
    printf("sqrt(n) = %d\n", m);
    k = m;
    while(arr[m] <= key) {
        i = m;
        m += k;
        printf("i = %d, m = %d\n", i, m);
        if(n % k != 0 && m > n) {
            remain = n % k;
            printf("remian = %d\n", remain);
            m -= k - remain;
            printf("after m = %d\n", m);
            break;
        }

        if(m > n)
            return -1;
    }

    for(j = i; j < m; j++) {
        if(arr[j] == key) {
            return j;
        }
    }

    return -1;
}