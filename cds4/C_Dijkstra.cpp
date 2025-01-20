#include <bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int s, vector<vector<pair<int, int>>>& g) {
	int n = g.size();
	vector<int> dist(n, 1000000);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s }); dist[s] = 0;

	while (!pq.empty()) {
		auto [distance, parent] = pq.top();pq.pop();
		if(distance>dist[parent]) continue;
		for (auto& [edge, node] : g[parent]) {
			if(dist[parent]+edge<dist[node]){
				dist[node] = dist[parent] + edge;
				pq.push({dist[node], node});
			}
		}
	}
	return dist;
}

int main() {
	vector<vector<pair<int, int>>> g = {
		{{1, 4}, {2, 1}},        // Node 0: (weight 4 -> 1), (weight 1 -> 2)
		{{2, 2}, {3, 5}},        // Node 1: (weight 2 -> 2), (weight 5 -> 3)
		{{3, 8}},                // Node 2: (weight 8 -> 3)
		{{4, 3}},                // Node 3: (weight 3 -> 4)
		{}                       // Node 4: No outgoing edges
	};
	vector<int> dist = dijkstra(0,g);
}
