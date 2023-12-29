/*
 * Author: Muhammad Xayrullayev
 * Date: 29.12.2023
 * Name: Muhammad Xayrullayev
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Problem4 {
public:
        struct Edge {
    int to;
    int weight;
};

int networkDelayTime(vector<vector<Edge>>& graph, int n, int k) {
    const int INF = INT_MAX;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    unordered_map<int, int> distance;

    pq.push({0, k});
    distance[k] = 0;

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        for (const Edge& edge : graph[currentNode]) {
            int newDistance = currentDistance + edge.weight;

            if (newDistance < distance[edge.to]) {
                distance[edge.to] = newDistance;
                pq.push({newDistance, edge.to});
            }
        }
    }

    if (distance.size() == n) {
        int maxDistance = 0;
        for (const auto& entry : distance) {
            maxDistance = max(maxDistance, entry.second);
        }
        return maxDistance;
    } else {
        return -1;
    }
}
};