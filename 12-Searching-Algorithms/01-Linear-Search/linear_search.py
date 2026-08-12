n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter elements: ").split()))

target = int(input("Enter element to search: "))

found = -1

for i in range(n):
    if arr[i] == target:
        found = i
        break

if found != -1:
    print("Element found at index:", found)
else:
    print("Element not found.")