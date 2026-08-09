import heapq

n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

graph = [[] for _ in range(n)]

print("Enter weighted edges (u v w):")

for _ in range(e):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

start = int(input("Enter source vertex: "))

INF = float("inf")
distance = [INF] * n
distance[start] = 0

pq = [(0, start)]

while pq:
    dist, node = heapq.heappop(pq)

    if dist > distance[node]:
        continue

    for neighbor, weight in graph[node]:
        new_dist = dist + weight

        if new_dist < distance[neighbor]:
            distance[neighbor] = new_dist
            heapq.heappush(pq, (new_dist, neighbor))

print("\nShortest distances from vertex", start)

for i in range(n):
    if distance[i] == INF:
        print(i, "-> INF")
    else:
        print(i, "->", distance[i])