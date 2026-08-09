def bucket_sort(arr):
    n = len(arr)

    buckets = [[] for _ in range(n)]

    for value in arr:
        index = int(value * n)
        buckets[index].append(value)

    for bucket in buckets:
        bucket.sort()

    result = []

    for bucket in buckets:
        result.extend(bucket)

    return result


n = int(input("Enter number of elements: "))
arr = list(map(float, input("Enter values between 0 and 1: ").split()))

if any(value < 0 or value >= 1 for value in arr):
    print("Values must be in the range [0, 1).")
else:
    arr = bucket_sort(arr)

    print("Sorted array:", arr)