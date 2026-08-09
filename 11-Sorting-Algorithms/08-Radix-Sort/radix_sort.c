#include <stdio.h>

#define MAX 100

void counting_sort(int arr[], int n, int exp) {
    int output[MAX];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative elements: ");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if(arr[i] < 0) {
            printf("Only non-negative integers are supported.\n");
            return 0;
        }
    }

    int maximum = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > maximum)
            maximum = arr[i];
    }

    for(int exp = 1; maximum / exp > 0; exp *= 10)
        counting_sort(arr, n, exp);

    printf("Sorted array: ");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}