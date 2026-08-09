n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

graph = [[] for _ in range(n)]

print("Enter edges (u v):")

for _ in range(e):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

start = int(input("Enter starting vertex: "))

visited = [False] * n

def dfs(node):
    visited[node] = True
    print(node, end=" ")

    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor)

print("DFS Traversal:", end=" ")
dfs(start)

print()