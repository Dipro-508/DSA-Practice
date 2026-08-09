#include <stdio.h>

#define MAX 100

void heapify_up(int heap[], int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;

        if(heap[parent] <= heap[index])
            break;

        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

int main() {
    int heap[MAX];
    int n;

    printf("Enter number of initial elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    int value;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    heap[n] = value;

    heapify_up(heap, n);

    n++;

    printf("Heap after insertion: ");

    for(int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");

    return 0;
}