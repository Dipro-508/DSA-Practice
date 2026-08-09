n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

edges = []

print("Enter weighted edges (u v w):")

for _ in range(e):
    u, v, w = map(int, input().split())
    edges.append((w, u, v))

edges.sort()

parent = list(range(n))
rank = [0] * n


def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])

    return parent[x]


def union(a, b):
    root_a = find(a)
    root_b = find(b)

    if root_a == root_b:
        return False

    if rank[root_a] < rank[root_b]:
        parent[root_a] = root_b

    elif rank[root_a] > rank[root_b]:
        parent[root_b] = root_a

    else:
        parent[root_b] = root_a
        rank[root_a] += 1

    return True


total_cost = 0
edges_used = 0

print("\nEdges in Minimum Spanning Tree:")

for weight, u, v in edges:

    if union(u, v):

        print(u, "--", v, "weight:", weight)

        total_cost += weight
        edges_used += 1

        if edges_used == n - 1:
            break

if edges_used != n - 1:
    print("\nMST is not possible because the graph is disconnected.")
else:
    print("\nMinimum Cost:", total_cost)