#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(sizeof(int) * n1);
    int *R = malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while ((i < n1) & (j < n2)){
        if (L[i] <= R[j]){
            arr[k++] = L[i++];
        }

        else {
            arr[k++] = R[j++];
        }
    }   

    while (i < n1) {arr[k++] = L[i++];}

    while (j < n2) {arr[k++] = R[j++];}

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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