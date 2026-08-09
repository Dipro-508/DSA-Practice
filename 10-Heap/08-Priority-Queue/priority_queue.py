import heapq

pq = []

n = int(input("Enter number of elements: "))

print("Enter elements:")

for _ in range(n):
    value = int(input())
    heapq.heappush(pq, value)

print("\nPriority Queue:", pq)

while pq:
    print("Removed:", heapq.heappop(pq))

print("Priority Queue is empty.")