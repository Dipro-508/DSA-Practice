def heapify(arr, n, i):
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] < arr[smallest]:
        smallest = left

    if right < n and arr[right] < arr[smallest]:
        smallest = right

    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        heapify(arr, n, smallest)


n = int(input("Enter number of elements: "))

arr = list(map(int, input("Enter elements: ").split()))

for i in range(n // 2 - 1, -1, -1):
    heapify(arr, n, i)

print("Min Heap:", arr)