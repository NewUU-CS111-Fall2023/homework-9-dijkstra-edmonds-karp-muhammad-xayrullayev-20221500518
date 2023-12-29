/*
 * Author: Muhammad Xayrullayev
 * Date: 29.12.2023
 * Name: Muhammad Xayrullayev
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class Problem5 {
public:
// Time complexity: O((E + V) * log(V))
    struct Flight {
    int to;
    int cost;
    int stops;
};

struct CompareFlights {
    bool operator()(const Flight& a, const Flight& b) {
        return a.cost > b.cost;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto& flight : flights) {
        graph[flight[0]].emplace_back(flight[1], flight[2]);
    }

    priority_queue<Flight, vector<Flight>, CompareFlights> pq;
    pq.push({src, 0, 0});

    while (!pq.empty()) {
        Flight currentFlight = pq.top();
        pq.pop();

        if (currentFlight.to == dst) {
            return currentFlight.cost;
        }

        if (currentFlight.stops <= k) {
            for (const auto& next : graph[currentFlight.to]) {
                pq.push({next.first, currentFlight.cost + next.second, currentFlight.stops + 1});
            }
        }
    }

    return -1;
}
    
};