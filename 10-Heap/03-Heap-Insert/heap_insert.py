def insert(heap, value):
    heap.append(value)

    i = len(heap) - 1

    while i > 0:
        parent = (i - 1) // 2

        if heap[parent] <= heap[i]:
            break

        heap[parent], heap[i] = heap[i], heap[parent]

        i = parent


n = int(input("Enter number of initial elements: "))

heap = list(map(int, input("Enter elements: ").split()))

for i in range(n // 2 - 1, -1, -1):
    smallest = i

    while True:
        left = 2 * smallest + 1
        right = 2 * smallest + 2
        current = smallest

        if left < n and heap[left] < heap[current]:
            current = left

        if right < n and heap[right] < heap[current]:
            current = right

        if current == smallest:
            break

        heap[smallest], heap[current] = heap[current], heap[smallest]
        smallest = current

value = int(input("Enter value to insert: "))

insert(heap, value)

print("Heap after insertion:", heap)