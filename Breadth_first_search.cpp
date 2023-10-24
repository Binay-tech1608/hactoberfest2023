#include <iostream>
#include <list>
#include <queue>

class Graph {
    int V; // Number of vertices

public:
    std::list<int> *adj; // Pointer to an array containing adjacency lists

    Graph(int V); // Constructor

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // Function to perform BFS from a given starting vertex
    void BFS(int start);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int start) {
    // Create a boolean array to track visited vertices
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    std::queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        // Dequeue a vertex from the queue and print it
        start = queue.front();
        std::cout << start << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it as visited and enqueue it
        for (const auto &neighbor : adj[start]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Breadth-First Traversal (starting from vertex 2): ";
    g.BFS(2);

    return 0;
}
