#include <stdio.h>

#define MAX 100

int binary_search(int arr[], int low, int high, int target) {
    if(low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if(arr[mid] == target)
        return mid;

    if(arr[mid] < target)
        return binary_search(arr, mid + 1, high, target);

    return binary_search(arr, low, mid - 1, target);
}

int main() {
    int arr[MAX], n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = binary_search(arr, 0, n - 1, target);

    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}