#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>>graph, vector<int>colors, int node, int n, int color) {
	for (int i = 0; i < n; i++) {
		if (i != node and graph[node][i] == true and colors[i] == color)    return false;
	}
	return true;
}

bool solve(vector<vector<bool>>graph, vector<int> &colors, int node, int n, int m) {

	if (node == n)    return true;

	for (int i = 1; i <= m; i++) {
		if (isSafe(graph, colors, node, n, i)) {
			colors[node] = i;
			if (solve(graph, colors, node + 1, n, m))    return true;
			colors[node] = 0;
		}
	}
	return false;
}

bool graphColoring(vector<vector<bool>>graph, int n, int m) {

	vector<int>colors(n, 0);
	if (solve(graph, colors, 0, n, m))    return true;
	return false;
}

int main() {
	int n;
	cin >> n;

	vector<vector<bool>>graph(n, vector<bool>(n, false));

	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 1)    graph[i][j] = true;
		}
	}

	int m;
	cin >> m;

	if (graphColoring(graph, n, m))    cout << "YES\n";
	else cout << "NO\n";

}