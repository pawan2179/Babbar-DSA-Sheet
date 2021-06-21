#include<bits/stdc++.h>
using namespace std;

void prims(vector<pair<int, int>>adj[], int n) {

	bool visited[n + 1];
	int mstCost = 0;

	int parent[n + 1];
	bool mst[n + 1];
	int key[n + 1];

	for (int i = 0; i <= n; i++) {
		parent[i] = -1;
		key[i] = INT_MAX;
		mst[i] = false;
	}

	key[1] = 0;

	for (int count = 0; count < n - 1; count++) {
		int mini = INT_MAX;
		int u;

		for (int i = 1; i <= n; i++) {
			if (mst[i] == false and key[i] < mini) {
				mini = key[i];
				u = i;
			}
		}
		mst[u] = true;

		for (auto edge : adj[u]) {

			int v = edge.first;
			int weight = edge.second;
			if (!mst[v] and weight < key[v]) {
				parent[v] = u;
				key[v] = weight;
			}
		}
	}
	for (int i = 1; i <= n; i++)    mstCost += key[i];

	cout << "MST Cost -> " << mstCost << endl;
	cout << "MST Structure -> " << endl;

	for (int i = 1; i <= n; i++) {
		cout << parent[i] << " --> " << i << " -- " << key[i] << endl;
	}
	return ;
}

int main() {
	int n, m;
	cin >> n >> m;

	int u, v, wt;

	vector<pair<int, int>>adj[n + 1];

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> wt;

		adj[u].push_back(make_pair(v, wt));
		adj[v].push_back(make_pair(u, wt));
	}

	prims(adj, n);
	return 0;
}