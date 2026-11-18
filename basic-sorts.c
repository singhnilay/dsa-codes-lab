#include <stdio.h>
#define SIZE 100

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){

    for (int i = 0; i < n - 1; i++){
        int minIdx = i;

        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIdx]){
                swap(&arr[minIdx], &arr[j]);
            }
        }

        
    }
}

void insertionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1;j++){
            while (arr[j+1] < arr[j]){
                swap(&arr[j+1], &arr[j]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Test all three sorting functions
void testSorts(int original[], int n) {
    int bubble[SIZE];
    int selection[SIZE];
    int insertion[SIZE];

    for (int i = 0; i < n; i++) {
        bubble[i] = original[i];
        selection[i] = original[i];
        insertion[i] = original[i];
    }

    printf("\n====================================\n");
    printf("Original array:  ");
    printArray(original, n);

    bubbleSort(bubble, n);
    printf("Bubble Sort:     ");
    printArray(bubble, n);

    selectionSort(selection, n);
    printf("Selection Sort:  ");
    printArray(selection, n);

    insertionSort(insertion, n);
    printf("Insertion Sort:  ");
    printArray(insertion, n);

    printf("====================================\n");
}

int main(void) {
    int arr1[] = {5, 2, 8, 1, 9, 3};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {5, 4, 3, 2, 1};
    int arr4[] = {7, 7, 2, 2, 5, 5};
    int arr5[] = {42};
    int arr6[] = {3, -1, 0, -5, 8, 2};

    printf("TEST CASE 1: Random order\n");
    testSorts(arr1, sizeof(arr1) / sizeof(arr1[0]));

    printf("\nTEST CASE 2: Already sorted\n");
    testSorts(arr2, sizeof(arr2) / sizeof(arr2[0]));

    printf("\nTEST CASE 3: Reverse sorted\n");
    testSorts(arr3, sizeof(arr3) / sizeof(arr3[0]));

    printf("\nTEST CASE 4: Duplicate values\n");
    testSorts(arr4, sizeof(arr4) / sizeof(arr4[0]));

    printf("\nTEST CASE 5: Single element\n");
    testSorts(arr5, sizeof(arr5) / sizeof(arr5[0]));

    printf("\nTEST CASE 6: Negative and zero values\n");
    testSorts(arr6, sizeof(arr6) / sizeof(arr6[0]));

    return 0;
}

