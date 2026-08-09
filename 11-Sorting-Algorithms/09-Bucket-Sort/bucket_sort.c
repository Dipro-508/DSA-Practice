#include <stdio.h>

#define MAX 100

void insertion_sort(float arr[], int n) {
    for(int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    float arr[MAX];
    float buckets[MAX][MAX];

    int bucket_count[MAX] = {0};
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter values between 0 and 1: ");

    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);

        if(arr[i] < 0 || arr[i] >= 1) {
            printf("Values must be in the range [0, 1).\n");
            return 0;
        }
    }

    for(int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);

        buckets[index][bucket_count[index]++] = arr[i];
    }

    for(int i = 0; i < n; i++)
        insertion_sort(buckets[i], bucket_count[i]);

    int index = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bucket_count[i]; j++)
            arr[index++] = buckets[i][j];
    }

    printf("Sorted array: ");

    for(int i = 0; i < n; i++)
        printf("%.3f ", arr[i]);

    printf("\n");

    return 0;
}