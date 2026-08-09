import time


def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        swapped = False

        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        if not swapped:
            break


def selection_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        minimum = i

        for j in range(i + 1, n):
            if arr[j] < arr[minimum]:
                minimum = j

        arr[i], arr[minimum] = arr[minimum], arr[i]


def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2

    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    result = []

    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result


def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[-1]

    left = [x for x in arr[:-1] if x <= pivot]
    right = [x for x in arr[:-1] if x > pivot]

    return quick_sort(left) + [pivot] + quick_sort(right)


n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter elements: ").split()))

algorithms = [
    ("Bubble Sort", bubble_sort),
    ("Selection Sort", selection_sort),
    ("Insertion Sort", insertion_sort)
]
for name, algorithm in algorithms:
    data = arr.copy()
    start = time.perf_counter()
    algorithm(data)
    end = time.perf_counter()
    print(name, ":", end - start, "seconds")
start = time.perf_counter()
merge_sort(arr.copy())
end = time.perf_counter()
print("Merge Sort :", end - start, "seconds")
start = time.perf_counter()
quick_sort(arr.copy())
end = time.perf_counter()
print("Quick Sort :", end - start, "seconds")