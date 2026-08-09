from collections import deque

n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

graph = [[] for _ in range(n)]

print("Enter edges (u v):")

for _ in range(e):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

start = int(input("Enter starting vertex: "))


def bfs(start):
    visited = [False] * n
    queue = deque([start])

    visited[start] = True

    print("BFS:", end=" ")

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

    print()


def dfs(node, visited):
    visited[node] = True
    print(node, end=" ")

    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, visited)


bfs(start)

visited = [False] * n

print("DFS:", end=" ")
dfs(start, visited)
print()