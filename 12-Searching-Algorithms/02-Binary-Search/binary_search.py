n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter sorted elements: ").split()))

target = int(input("Enter element to search: "))

low = 0
high = n - 1
found = -1

while low <= high:
    mid = low + (high - low) // 2

    if arr[mid] == target:
        found = mid
        break

    elif arr[mid] < target:
        low = mid + 1

    else:
        high = mid - 1

if found != -1:
    print("Element found at index:", found)
else:
    print("Element not found.")