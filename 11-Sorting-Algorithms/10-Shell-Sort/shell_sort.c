#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int gap = n / 2; gap > 0; gap /= 2) {

        for(int i = gap; i < n; i++) {

            int key = arr[i];
            int j = i;

            while(j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = key;
        }
    }

    printf("Sorted array: ");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}