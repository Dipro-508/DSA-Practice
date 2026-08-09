n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

graph = [[] for _ in range(n)]

print("Enter edges (u v):")

for _ in range(e):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

print("\nAdjacency List:")

for i in range(n):
    print(i, "->", graph[i])