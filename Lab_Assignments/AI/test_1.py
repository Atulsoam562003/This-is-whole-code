import numpy as np
import math as math
from collections import deque

def bfs(m, n, d):
    q = deque()
    q.append((0, 0, []))
    visited = set()
    visited.add((0, 0))
    while q:
        x, y, path = q.popleft()
        if x + y == d:
            print("All Visited States: ", visited)
            return (x, y, path)

        if x < m and (x+1, y) not in visited:
            q.append((x+1, y, path + [f"Fill {m}-liter jug"]))
            visited.add((x+1, y))

        if y < n and (x, y+1) not in visited:
            q.append((x, y+1, path + [f"Fill {n}-liter jug"]))
            visited.add((x, y+1))

        if x > 0 and (0, y) not in visited:
            q.append((0, y, path + [f"Empty {m}-liter jug"]))
            visited.add((0, y))

        if y > 0 and (x, 0) not in visited:
            q.append((x, 0, path + [f"Empty {n}-liter jug"]))
            visited.add((x, 0))

        if x > 0 and y < n:
            transfer = min(x, n-y)
            if (x-transfer, y+transfer) not in visited:
                q.append((x-transfer, y+transfer, path + [f"Transfer {transfer} liters from {m}-liter jug to {n}-liter jug"]))
                visited.add((x-transfer, y+transfer))

        if y > 0 and x < m:
            transfer = min(y, m-x)
            if (x+transfer,y-transfer) not in visited:
                q.append((x+transfer, y-transfer, path + [f"Transfer {transfer} liters from {n}-liter jug to {m}-liter jug"]))
                visited.add((x+transfer, y-transfer))
    return None

m = 4
n = 5
d = 7
x ,y , path = bfs(m, n, d)

if x is not None:
    print("The goal state is reached:", (x , y))
    print("Steps to reach the goal state:", path)
else:
    print("It is not possible to reach the goal state.")
    print("All Visited States: ", visited)


