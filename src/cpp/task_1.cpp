/*
 * Author: Muhammad Xayrullayev
 * Date: 29.12.2023
 * Name: Muhammad Xayrullayev
 */
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Problem1 {
public:
    struct Edge {
    int to;
    int weight;
};

struct Node {
    int id;
    int distance;
};

// Time complexity: O(E * log(V))
struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};

// Time complexity: O((E + V) * log(V))
void dijkstra(vector<vector<Edge>>& graph, int start) {
    int numNodes = graph.size();

    priority_queue<Node, vector<Node>, CompareNodes> pq;

    vector<int> distance(numNodes, numeric_limits<int>::max());

    distance[start] = 0;

    pq.push({start, 0});

    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();

        for (const Edge& edge : graph[currentNode.id]) {
            int newDistance = currentNode.distance + edge.weight;
            
            if (newDistance < distance[edge.to]) {
                distance[edge.to] = newDistance;
                pq.push({edge.to, newDistance});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << "To node " << i << ": " << distance[i] << "\n";
    }
}

};
