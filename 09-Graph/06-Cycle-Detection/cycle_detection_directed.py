n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

graph = [[] for _ in range(n)]

print("Enter directed edges (u v):")

for _ in range(e):
    u, v = map(int, input().split())
    graph[u].append(v)

visited = [False] * n
rec_stack = [False] * n


def has_cycle(node):
    visited[node] = True
    rec_stack[node] = True

    for neighbor in graph[node]:

        if not visited[neighbor]:
            if has_cycle(neighbor):
                return True

        elif rec_stack[neighbor]:
            return True

    rec_stack[node] = False

    return False


cycle = False

for i in range(n):
    if not visited[i]:
        if has_cycle(i):
            cycle = True
            break

if cycle:
    print("Cycle detected!")
else:
    print("No cycle detected.")