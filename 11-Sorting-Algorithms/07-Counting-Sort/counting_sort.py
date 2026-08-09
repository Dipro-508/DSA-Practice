n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter non-negative elements: ").split()))

if any(x < 0 for x in arr):
    print("Only non-negative integers are supported.")
else:
    maximum = max(arr)

    count = [0] * (maximum + 1)

    for value in arr:
        count[value] += 1

    index = 0

    for value in range(maximum + 1):
        while count[value] > 0:
            arr[index] = value
            index += 1
            count[value] -= 1

    print("Sorted array:", arr)