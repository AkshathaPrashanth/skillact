#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Sort the left part
        quickSort(arr, pi + 1, high); // Sort the right part
    }
}

// Function to find the k-th smallest element
int kthSmallest(int arr[], int n, int k) {
    quickSort(arr, 0, n - 1);
    return arr[k - 1];  // Since arrays are 0-indexed, the k-th smallest is at index k-1
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;  // Example: Finding the 4th smallest element

    int result = kthSmallest(arr, n, k);
    printf("The %d-th smallest element is %d\n", k, result);

    return 0;
}
