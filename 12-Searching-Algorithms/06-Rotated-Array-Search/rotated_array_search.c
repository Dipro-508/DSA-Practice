#include <stdio.h>

#define MAX 100

int search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
            return mid;

        if(arr[low] <= arr[mid]) {

            if(arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {

            if(arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[MAX], n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter rotated sorted elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = search(arr, n, target);

    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}