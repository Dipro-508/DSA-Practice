def search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = low + (high - low) // 2

        if arr[mid] == target:
            return mid

        if arr[low] <= arr[mid]:

            if arr[low] <= target < arr[mid]:
                high = mid - 1
            else:
                low = mid + 1

        else:

            if arr[mid] < target <= arr[high]:
                low = mid + 1
            else:
                high = mid - 1

    return -1


n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter rotated sorted elements: ").split()))

target = int(input("Enter element to search: "))

result = search(arr, target)

if result != -1:
    print("Element found at index:", result)
else:
    print("Element not found.")