import heapq

n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

graph = [[] for _ in range(n)]

print("Enter weighted edges (u v w):")

for _ in range(e):
    u, v, w = map(int, input().split())

    graph[u].append((v, w))
    graph[v].append((u, w))

start = int(input("Enter starting vertex: "))

visited = [False] * n
pq = [(0, start, -1)]

total_cost = 0
edges_used = 0

print("\nEdges in Minimum Spanning Tree:")

while pq:

    weight, node, parent = heapq.heappop(pq)

    if visited[node]:
        continue

    visited[node] = True

    if parent != -1:
        print(parent, "--", node, "weight:", weight)
        total_cost += weight
        edges_used += 1

    for neighbor, edge_weight in graph[node]:
        if not visited[neighbor]:
            heapq.heappush(
                pq,
                (edge_weight, neighbor, node)
            )

if edges_used != n - 1:
    print("\nMST is not possible because the graph is disconnected.")
else:
    print("\nMinimum Cost:", total_cost)