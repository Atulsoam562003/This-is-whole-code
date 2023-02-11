from collections import deque

def bfs(m, n, d):
    q = deque()
    q.append((0, 0))
    visited = set()
    visited.add((0, 0))
    while q:
        x, y = q.popleft()
        if x + y == d:
            return (x, y)
        # Fill up the m-liter jug
        if x < m and (x+1, y) not in visited:
            q.append((x+1, y))
            visited.add((x+1, y))
        # Fill up the n-liter jug
        if y < n and (x, y+1) not in visited:
            q.append((x, y+1))
            visited.add((x, y+1))
        # Empty the m-liter jug
        if x > 0 and (0, y) not in visited:
            q.append((0, y))
            visited.add((0, y))
        # Empty the n-liter jug
        if y > 0 and (x, 0) not in visited:
            q.append((x, 0))
            visited.add((x, 0))
        # Transfer water from the m-liter jug to the n-liter jug
        if x > 0 and y < n:
            transfer = min(x, n-y)
            if (x-transfer, y+transfer) not in visited:
                q.append((x-transfer, y+transfer))
                visited.add((x-transfer, y+transfer))
        # Transfer water from the n-liter jug to the m-liter jug
        if y > 0 and x < m:
            transfer = min(y, m-x)
            if (x+transfer, y-transfer) not in visited:
                q.append((x+transfer, y-transfer))
                visited.add((x+transfer, y-transfer))
    return None

m = 4
n = 5
d = 7
result = bfs(m, n, d)
if result is not None:
    print("The goal state is reached:", result)
else:
    print("It is not possible to reach the goal state.")
