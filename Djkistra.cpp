 #include <iostream>
 #include <vector>
 #include <queue>
 #include <limits> // For numeric_limits
      
using namespace std;
      
      // Define infinity for distance calculations
      const int INF = numeric_limits<int>::max();
     
      // Structure to represent an edge in the graph
    struct Edge {
         int to;
         int weight;
    
         // Custom comparator for priority queue
         bool operator>(const Edge& other) const {
             return weight > other.weight;
         }
     };
     
     // Function to implement Dijkstra's algorithm
     vector<int> dijkstra(int numNodes, const vector<vector<Edge>>& adj, int startNode) {
        // Distance array, initialized with infinity
         std::vector<int> dist(numNodes, INF);
         // Priority queue to store {distance, node} pairs
         priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
     
         // Distance to the start node is 0
         dist[startNode] = 0;
         pq.push({startNode, 0});
     
     while (!pq.empty()) {
             int u = pq.top().to;
             int d = pq.top().weight;
             pq.pop();
    
             // If we've found a shorter path to u already, skip
             if (d > dist[u]) {
                 continue;
             }
 
            // Iterate over all neighbors of u
             for (const Edge& edge : adj[u]) {
                 int v = edge.to;
                 int weight = edge.weight;
     
             // If a shorter path to v is found
                 if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                     pq.push({v, dist[v]});
                 }
          }
        }
         return dist;
     }
     
     int main() {
         // Example Usage:
         int numNodes = 5; // Number of nodes in the graph
         // Adjacency list representation: adj[u] stores a list of edges from u
         vector<std::vector<Edge>> adj(numNodes);
     
     // Adding edges to the graph (node, weight)
         // Node 0
         adj[0].push_back({1, 10});
        adj[0].push_back({2, 3});
          // Node 1
         adj[1].push_back({0, 10}); // Bidirectional if needed, but Dijkstra works with directed graphs too
         adj[1].push_back({2, 1});
         adj[1].push_back({3, 2});
     
         // Node 2
         adj[2].push_back({0, 3});
         adj[2].push_back({1, 1});
         adj[2].push_back({3, 8});
         adj[2].push_back({4, 2}); 
         // Node 3
       adj[3].push_back({1, 2});
        adj[3].push_back({2, 8});
         adj[3].push_back({4, 7});
     
         // Node 4
         adj[4].push_back({2, 2});
         adj[4].push_back({3, 7});
     
         int startNode = 0; // Starting node for Dijkstra's algorithm
     
         vector<int> shortestDistances = dijkstra(numNodes, adj, startNode);
     
         cout << "Shortest distances from node " << startNode << ":" << std::endl;
         for (int i = 0; i < numNodes; ++i) {
             if (shortestDistances[i] == INF) {
             cout << "To node " << i << ": INF" << std::endl;
            } else {
                 cout << "To node " << i << ": " << shortestDistances[i] << std::endl;         }
        }
    
        return 0;
    }
