#include<bits/stdc++.h>
using namespace std;

int min_unvisited_distance(vector<bool> traversed, vector<int>distance, int n) {
	int u;
	int min_distance = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (!traversed[i] and distance[i] < min_distance) {
			min_distance = distance[i];
			u = i;
		}
	}
	return u;
}

void dijkstra(int src, vector<vector<pair<int, int>>>graph, vector<bool>&traversed, vector<int> &distance, int n) {
	distance[src] = 0;

	for (int count = 0; count < n - 1; count++) {
		int u = min_unvisited_distance(traversed, distance, n);
		traversed[u] = true;

		for (pair p : graph[u]) {
			if (!traversed[p.first]) {
				distance[p.first] = min(distance[p.first], distance[u] + p.second);
			}
		}
	}
	return ;
}

void printMinDistance(vector<int>distance) {
	for (auto x : distance) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	int n, m;
	int u, v, w;
	cin >> n >> m;

	vector<vector<pair<int, int>>>graph(n);

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	vector<bool>traversed(n, false);
	vector<int>distance(n, INT_MAX);

	int src;
	cin >> src;

	dijkstra(src, graph, traversed, distance, n);

	printMinDistance(distance);
	return 0;

}