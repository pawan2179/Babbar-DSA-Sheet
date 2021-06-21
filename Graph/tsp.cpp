#include<bits/stdc++.h>
using namespace std;

int tsp(int mask, int src, vector<vector<int>> &dist, int visited_all, int n, vector<vector<int>> &dp) {
	if (mask == visited_all)    return dist[src][0];

	if (dp[mask][src] != -1)    return dp[mask][src];

	int ans = INT_MAX;

	for (int i = 0; i < n; i++) {
		//cout << mask << " " << i << " " << (mask & (1 << i)) << endl;
		if ((mask & (1 << i)) == 0) {
			//cout << "In loop\n";
			int newAns = dist[src][i] + tsp((mask | (1 << i)), i, dist, visited_all, n, dp);
			ans = min(newAns, ans);
		}
	}
	return dp[mask][src] = ans;
}

int main() {
	int n;
	int x, y, wt;

	cin >> n;

	int visited_all = (1 << n) - 1;

	vector<vector<int>> dist(n, vector<int>(n, 0));
	vector<vector<int>> dp(pow(2, n), vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	cout << tsp(1, 0, dist, visited_all, n, dp);
	return 0;
}