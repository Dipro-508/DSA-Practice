#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n, target;
    int low, high, mid;
    int found = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &target);

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            found = mid;
            break;
        }

        if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found != -1)
        printf("Element found at index: %d\n", found);
    else
        printf("Element not found.\n");

    return 0;
}