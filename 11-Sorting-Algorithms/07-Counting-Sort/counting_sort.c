#include <stdio.h>

#define MAX 100
#define RANGE 1000

int main() {
    int arr[MAX], count[RANGE] = {0};
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative elements: ");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if(arr[i] < 0 || arr[i] >= RANGE) {
            printf("Invalid value. Use values from 0 to %d.\n",
                   RANGE - 1);
            return 0;
        }

        count[arr[i]]++;
    }

    int index = 0;

    for(int i = 0; i < RANGE; i++) {
        while(count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    printf("Sorted array: ");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}