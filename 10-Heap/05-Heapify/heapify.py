def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter elements: ").split()))

index = int(input("Enter index to heapify: "))

if 0 <= index < n:
    heapify(arr, n, index)
    print("After Heapify:", arr)
else:
    print("Invalid index.")