n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

graph = [[] for _ in range(n)]

print("Enter edges (u v):")

for _ in range(e):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [False] * n


def has_cycle(node, parent):
    visited[node] = True

    for neighbor in graph[node]:
        if not visited[neighbor]:
            if has_cycle(neighbor, node):
                return True
        elif neighbor != parent:
            return True

    return False


cycle = False

for i in range(n):
    if not visited[i]:
        if has_cycle(i, -1):
            cycle = True
            break

if cycle:
    print("Cycle detected!")
else:
    print("No cycle detected.")