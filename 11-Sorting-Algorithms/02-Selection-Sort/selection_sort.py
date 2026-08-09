n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter elements: ").split()))

for i in range(n - 1):
    minimum = i

    for j in range(i + 1, n):
        if arr[j] < arr[minimum]:
            minimum = j

    arr[i], arr[minimum] = arr[minimum], arr[i]

print("Sorted array:", arr)