#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

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

    printf("Sorted array: ");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}