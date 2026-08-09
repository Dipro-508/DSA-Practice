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

void heapify_down(int heap[], int n, int index) {
    while(1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < n && heap[left] < heap[smallest])
            smallest = left;

        if(right < n && heap[right] < heap[smallest])
            smallest = right;

        if(smallest == index)
            break;

        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

void insert(int heap[], int *n, int value) {
    heap[*n] = value;
    heapify_up(heap, *n);
    (*n)++;
}

int delete_min(int heap[], int *n) {
    int value = heap[0];

    heap[0] = heap[*n - 1];
    (*n)--;

    if(*n > 0)
        heapify_down(heap, *n, 0);

    return value;
}

int main() {
    int heap[MAX];
    int n = 0;
    int count;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    printf("Enter elements:\n");

    for(int i = 0; i < count; i++) {
        int value;

        scanf("%d", &value);

        insert(heap, &n, value);
    }

    printf("\nPriority Queue: ");

    for(int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n\nRemoving elements:\n");

    while(n > 0) {
        printf("Removed: %d\n", delete_min(heap, &n));
    }

    printf("Priority Queue is empty.\n");

    return 0;
}