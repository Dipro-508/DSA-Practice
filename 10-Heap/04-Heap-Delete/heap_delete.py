def heapify_down(heap, n, i):
    while True:
        smallest = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < n and heap[left] < heap[smallest]:
            smallest = left

        if right < n and heap[right] < heap[smallest]:
            smallest = right

        if smallest == i:
            break

        heap[i], heap[smallest] = heap[smallest], heap[i]
        i = smallest


n = int(input("Enter number of elements: "))
heap = list(map(int, input("Enter elements: ").split()))

for i in range(n // 2 - 1, -1, -1):
    heapify_down(heap, n, i)

if n == 0:
    print("Heap is empty.")
else:
    removed = heap[0]

    heap[0] = heap[n - 1]
    heap.pop()

    heapify_down(heap, len(heap), 0)

    print("Deleted element:", removed)
    print("Heap after deletion:", heap)