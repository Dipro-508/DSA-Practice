#include <stdio.h>

#define MAX 100

int search_insert(int arr[], int n, int target) {
    int low = 0;
    int high = n;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    int arr[MAX], n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    int position = search_insert(arr, n, target);

    printf("Search insert position: %d\n", position);

    return 0;
}