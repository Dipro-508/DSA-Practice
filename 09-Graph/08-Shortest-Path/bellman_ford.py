n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

edges = []

print("Enter weighted edges (u v w):")

for _ in range(e):
    u, v, w = map(int, input().split())
    edges.append((u, v, w))

start = int(input("Enter source vertex: "))

INF = float("inf")
distance = [INF] * n

distance[start] = 0

for _ in range(n - 1):

    updated = False

    for u, v, w in edges:

        if distance[u] != INF:
            new_distance = distance[u] + w

            if new_distance < distance[v]:
                distance[v] = new_distance
                updated = True

    if not updated:
        break

negative_cycle = False

for u, v, w in edges:

    if distance[u] != INF and distance[u] + w < distance[v]:
        negative_cycle = True
        break

if negative_cycle:
    print("Negative-weight cycle detected!")
else:

    print("\nShortest distances from vertex", start)

    for i in range(n):

        if distance[i] == INF:
            print(i, "-> INF")
        else:
            print(i, "->", distance[i])