#include <stdio.h>

#define MAX 100

void heapify_down(int heap[], int n, int i) {
    while(1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && heap[left] < heap[smallest])
            smallest = left;

        if(right < n && heap[right] < heap[smallest])
            smallest = right;

        if(smallest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }
}

int main() {
    int heap[MAX];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    for(int i = n / 2 - 1; i >= 0; i--)
        heapify_down(heap, n, i);

    if(n == 0) {
        printf("Heap is empty.\n");
        return 0;
    }

    int removed = heap[0];

    heap[0] = heap[n - 1];
    n--;

    heapify_down(heap, n, 0);

    printf("Deleted element: %d\n", removed);

    printf("Heap after deletion: ");

    for(int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");

    return 0;
}