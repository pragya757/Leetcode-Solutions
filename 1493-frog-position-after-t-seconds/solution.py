
from collections import defaultdict, deque
from typing import List

class Solution:
    def frogPosition(
        self, n: int, edges: List[List[int]], t: int, target: int
    ) -> float:
        # Build adjacency list representation of the tree
        graph = defaultdict(list)
        for node_u, node_v in edges:
            graph[node_u].append(node_v)
            graph[node_v].append(node_u)
      
        # Initialize BFS queue with starting position (node 1) and probability 1.0
        queue = deque([(1, 1.0)])
      
        # Track visited nodes to avoid revisiting
        visited = [False] * (n + 1)
        visited[1] = True
      
        # Perform BFS for exactly t seconds
        while queue and t >= 0:
            # Process all nodes at current time step
            level_size = len(queue)
            for _ in range(level_size):
                current_node, probability = queue.popleft()
              
                # Calculate number of unvisited children
                # For root node (1), all neighbors are children
                # For other nodes, subtract 1 to exclude the parent
                unvisited_children_count = len(graph[current_node]) - int(current_node != 1)
              
                # Check if we've reached the target node
                if current_node == target:
                    # Frog stays at target if no unvisited children or no time left
                    # Otherwise, frog must jump away, so probability becomes 0
                    return probability if unvisited_children_count * t == 0 else 0
              
                # Add unvisited neighbors to queue for next time step
                for neighbor in graph[current_node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        # Probability is divided equally among unvisited children
                        queue.append((neighbor, probability / unvisited_children_count))
          
            # Decrement time after processing current level
            t -= 1
      
        # Target not reached within time limit
        return 0
