#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int>b) {
	return a[0] < b[0];
}

//Funtion to return actual parent of given node
int findParent(int a, int *parent) {
	if (parent[a] == a)    return a;
	return findParent(parent[a], parent);
}

//Funtion to perform a union b
void unionn(int a, int b, int *parent, int *rank) {

	a = findParent(a, parent);
	b = findParent(b, parent);

	if (rank[a] < rank[b])    parent[a] = b;
	else if (rank[a] > rank[b])    parent[b] = a;
	else {
		parent[a] = b;
		rank[b]++;
	}
	return;
}

void kruskal(vector<vector<int>>graph, int n) {

	int parent[n + 1];
	int rank[n + 1];
	int mstCost = 0;
	vector<pair<int, int>>mst;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}

	//Step 1 - Sort the edge list on basis of weight
	sort(graph.begin(), graph.end(), compare);

	//Step 2 - Select the nodes which don't already belong to same component
	for (auto edge : graph) {
		if (findParent(edge[1], parent) == findParent(edge[2], parent))    continue;

		mstCost += edge[0];
		mst.push_back(make_pair(edge[1], edge[2]));
		unionn(edge[1], edge[2], parent, rank);
	}

	cout << "MST Cost -> " << mstCost << endl;
	cout << "MST Edges -> " << endl;
	for (auto edge : mst) {
		cout << edge.first << " " << edge.second << endl;
	}
	return ;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>>graph;

	int u, v, wt;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> wt;
		graph.push_back({wt, u, v});
	}

	kruskal(graph, n);
	return 0;
}