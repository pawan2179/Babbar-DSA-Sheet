#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	int arr[m];

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		//hashmap[arr[i]] = 1;
	}

	int dp[n + 1] = {0};
	dp[0] = 1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= n; j++) {
			if (j - arr[i] >= 0) {
				dp[j] += dp[j - arr[i]];
			}
		}
	}
	cout << dp[n];

	return 0;

}