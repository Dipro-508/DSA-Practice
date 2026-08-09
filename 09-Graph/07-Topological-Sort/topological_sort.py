from collections import deque

n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

graph = [[] for _ in range(n)]
indegree = [0] * n

print("Enter directed edges (u v):")

for _ in range(e):
    u, v = map(int, input().split())
    graph[u].append(v)
    indegree[v] += 1

queue = deque()

for i in range(n):
    if indegree[i] == 0:
        queue.append(i)

topological_order = []

while queue:
    node = queue.popleft()
    topological_order.append(node)

    for neighbor in graph[node]:
        indegree[neighbor] -= 1

        if indegree[neighbor] == 0:
            queue.append(neighbor)

if len(topological_order) != n:
    print("Topological sort is not possible.")
    print("The graph contains a cycle.")
else:
    print("Topological Order:", end=" ")

    for node in topological_order:
        print(node, end=" ")

    print()