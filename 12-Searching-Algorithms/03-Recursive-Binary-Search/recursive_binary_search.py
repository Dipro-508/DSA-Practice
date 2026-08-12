def binary_search(arr, low, high, target):
    if low > high:
        return -1

    mid = low + (high - low) // 2

    if arr[mid] == target:
        return mid

    if arr[mid] < target:
        return binary_search(arr, mid + 1, high, target)

    return binary_search(arr, low, mid - 1, target)


n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter sorted elements: ").split()))

target = int(input("Enter element to search: "))

result = binary_search(arr, 0, n - 1, target)

if result != -1:
    print("Element found at index:", result)
else:
    print("Element not found.")