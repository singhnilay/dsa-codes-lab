#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++){
        L[i] = arr[low + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while ((i < n1) && (j < n2)){
        if (L[i] <= R[j]){
            arr[k++] = L[i++];
        }

        else {
            arr[k++] = R[j++];
        }
    }   
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int low, int high){
    int mid = low + (high - low) / 2;

    if (low < high)
    {
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    
}


void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {8,7,6,5,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("After:  ");
    printArray(arr, n);

    return 0;
}


