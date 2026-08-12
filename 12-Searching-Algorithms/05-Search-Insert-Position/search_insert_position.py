def search_insert(arr, target):
    low = 0
    high = len(arr)

    while low < high:
        mid = low + (high - low) // 2

        if arr[mid] < target:
            low = mid + 1
        else:
            high = mid

    return low


n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter sorted elements: ").split()))

target = int(input("Enter target: "))

position = search_insert(arr, target)

print("Search insert position:", position)