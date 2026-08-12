#include <stdio.h>

#define MAX 100

int first_occurrence(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            result = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return result;
}

int last_occurrence(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            result = mid;
            low = mid + 1;
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return result;
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

    int first = first_occurrence(arr, n, target);
    int last = last_occurrence(arr, n, target);

    if(first == -1) {
        printf("Element not found.\n");
    }
    else {
        printf("First occurrence: %d\n", first);
        printf("Last occurrence: %d\n", last);
    }

    return 0;
}