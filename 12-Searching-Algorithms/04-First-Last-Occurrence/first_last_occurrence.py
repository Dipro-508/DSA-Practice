def first_occurrence(arr, target):
    low = 0
    high = len(arr) - 1
    result = -1

    while low <= high:
        mid = low + (high - low) // 2

        if arr[mid] == target:
            result = mid
            high = mid - 1

        elif arr[mid] < target:
            low = mid + 1

        else:
            high = mid - 1

    return result


def last_occurrence(arr, target):
    low = 0
    high = len(arr) - 1
    result = -1

    while low <= high:
        mid = low + (high - low) // 2

        if arr[mid] == target:
            result = mid
            low = mid + 1

        elif arr[mid] < target:
            low = mid + 1

        else:
            high = mid - 1

    return result


n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter sorted elements: ").split()))

target = int(input("Enter element to search: "))

first = first_occurrence(arr, target)
last = last_occurrence(arr, target)

if first == -1:
    print("Element not found.")
else:
    print("First occurrence:", first)
    print("Last occurrence:", last)