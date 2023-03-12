import random
from typing import List, Tuple

class Graph:
    def __init__(self, V: List[int], E: List[Tuple[int, int]]):
        self.V = V
        self.E = E

    def get_neighbors(self, vertex_cover: List[int]) -> List[List[int]]:
        neighbors = []
        for i in range(len(self.V)):
            if self.V[i] not in vertex_cover:
                new_vertex_cover = vertex_cover.copy()
                new_vertex_cover.append(self.V[i])
                neighbors.append(new_vertex_cover)
        return neighbors

    def cost(self, vertex_cover: List[int]) -> int:
        return len(vertex_cover)

    def hill_climbing(self):
        current_vertex_cover = []
        for i in range(len(self.V)):
            if random.random() < 0.5:
                current_vertex_cover.append(self.V[i])
        while True:
            neighbors = self.get_neighbors(current_vertex_cover)
            if not neighbors:
                break
            neighbor_costs = [self.cost(neighbor) for neighbor in neighbors]
            min_cost_neighbor = neighbors[neighbor_costs.index(min(neighbor_costs))]
            if self.cost(min_cost_neighbor) >= self.cost(current_vertex_cover):
                break
            current_vertex_cover = min_cost_neighbor
        return current_vertex_cover

# Example usage:
V = [1, 2, 3, 4, 5, 6, 7, 8]
E = [(1, 2), (1, 3), (2, 4), (3, 4), (3, 5), (4, 6), (5, 6), (5, 7), (6, 8), (7, 8)]
graph = Graph(V, E)
vertex_cover = graph.hill_climbing()
print("Minimum vertex cover size:", len(vertex_cover))
print("Minimum vertex cover:", vertex_cover)
