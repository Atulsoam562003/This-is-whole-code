import math
import heapq

def apply_operations(n):
    return [math.gamma(n+1), math.sqrt(n), math.floor(n)]

def apply_operation(op, n):
    if op == "fact":
        return math.gamma(n+1)
    elif op == "sqrt":
        return math.sqrt(n)
    elif op == "floor":
        return math.floor(n)

def knuth_conjecture(start, goal):
    heap = [(0, start, [])]
    visited = set()
    while heap:
        _, node, path = heapq.heappop(heap)
        if node == goal:
            return path
        if node in visited:
            continue
        visited.add(node)
        for op in ["fact", "sqrt", "floor"]:
            child = apply_operation(op, node)
            if child < 1:
                continue
            heapq.heappush(heap, (len(path) + 1 + abs(child - goal), child, path + [op]))
    return None

start = 4
goal = 7
path = knuth_conjecture(start, goal)
if path:
    print("Steps to reach", goal, "starting from", start, ":")
    print(path)
else:
    print("Goal", goal, "cannot be reached from", start, "using factorial, square root, and floor operations.")