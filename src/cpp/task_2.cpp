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

class Problem2 {
public:
    struct Edge {
    int to;
    int capacity;
    int flow;
};
// Time complexity: O(VE^2)
int edmondsKarp(vector<vector<Edge>>& graph, int source, int sink) {
    int flow = 0;

    while (true) {
        queue<int> q;
        q.push(source);

        vector<int> pred(graph.size(), -1);
        pred[source] = source;

        while (!q.empty() && pred[sink] == -1) {
            int current = q.front();
            q.pop();

            for (const Edge& e : graph[current]) {
                if (pred[e.to] == -1 && e.to != source && e.capacity > e.flow) {
                    pred[e.to] = current;
                    q.push(e.to);
                }
            }
        }

        if (pred[sink] == -1) {
            break;
        }

        int pathFlow = numeric_limits<int>::max();

        for (int u = sink; u != source; u = pred[u]) {
            for (const Edge& e : graph[pred[u]]) {
                if (e.to == u) {
                    pathFlow = min(pathFlow, e.capacity - e.flow);
                    break;
                }
            }
        }

        for (int u = sink; u != source; u = pred[u]) {
            for (Edge& e : graph[pred[u]]) {
                if (e.to == u) {
                    e.flow += pathFlow;
                    break;
                }
            }

            for (Edge& e : graph[u]) {
                if (e.to == pred[u]) {
                    e.flow -= pathFlow;
                    break;
                }
            }
        }

        flow += pathFlow;
    }

    return flow;
}
};