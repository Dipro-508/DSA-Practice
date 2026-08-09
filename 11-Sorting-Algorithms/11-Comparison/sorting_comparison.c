#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        if(!swapped)
            break;
    }
}

void selection_sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minimum = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minimum])
                minimum = j;
        }

        int temp = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int temp[MAX];

    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left; i <= right; i++)
        arr[i] = temp[i];
}

void merge_sort(int arr[], int left, int right) {
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);

        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

void copy_array(int source[], int destination[], int n) {
    for(int i = 0; i < n; i++)
        destination[i] = source[i];
}

void test_sort(
    int original[],
    int n,
    void (*sort_function)(int[], int),
    char name[]
) {
    int arr[MAX];

    copy_array(original, arr, n);

    clock_t start = clock();

    sort_function(arr, n);

    clock_t end = clock();

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("%s: %.6f seconds\n",
           name,
           time_taken);
}

int main() {
    int arr[MAX];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nSorting Performance:\n");

    test_sort(arr, n, bubble_sort, "Bubble Sort");
    test_sort(arr, n, selection_sort, "Selection Sort");
    test_sort(arr, n, insertion_sort, "Insertion Sort");

    int temp[MAX];

    copy_array(arr, temp, n);

    clock_t start = clock();

    merge_sort(temp, 0, n - 1);

    clock_t end = clock();

    printf("Merge Sort: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    copy_array(arr, temp, n);

    start = clock();

    quick_sort(temp, 0, n - 1);

    end = clock();

    printf("Quick Sort: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}