#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void delete_max(int arr[], int* n) {
    if (*n <= 0) {
        printf("Heap is empty.\n");
        return;
    }

    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
        heapify(arr, *n, 0);

    printf("Deleted maximum element: %d\n", max);
}

int main() {
    int arr[] = { 44,56,34,12,43,67,89,50,60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Min-max heap before deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    delete_max(arr, &n);

    printf("Min-max heap after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
      return 0;
}
