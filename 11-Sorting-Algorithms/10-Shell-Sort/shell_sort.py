n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter elements: ").split()))

gap = n // 2

while gap > 0:

    for i in range(gap, n):
        key = arr[i]
        j = i

        while j >= gap and arr[j - gap] > key:
            arr[j] = arr[j - gap]
            j -= gap

        arr[j] = key

    gap //= 2

print("Sorted array:", arr)