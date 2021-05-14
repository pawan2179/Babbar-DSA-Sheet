#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int n, int m, int i, int j, vector<vector<int>> &dp) {

	if (i == n || j == m)    return 0;

	if (dp[i][j] != -1)    return dp[i][j];

	if (a[i] == b[j])    return dp[i][j] = 1 + LCS(a, b, n, m, i + 1, j + 1, dp);
	else {
		int op1 = LCS(a, b, n, m, i + 1, j, dp);
		int op2 = LCS(a, b, n, m, i, j + 1, dp);

		return dp[i][j] = max(op1, op2);
	}
	return 0;
}

void LCS_bottomUp(string s1, string s2) {

	int n1 = s1.length();
	int n2 = s2.length();

	vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, 0));

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (s1[i - 1] == s2[j - 1])    dp[i][j] = 1 + dp[i - 1][j - 1];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	string ans = "";
	int i = n1;
	int j = n2;

	while (i > 0 and j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			ans += s1[i - 1];
			i--;
			j--;
		}
		else {
			if (dp[i - 1][j] == dp[i][j])    i -= 1;
			else j -= 1;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << "Length = " << dp[n1][n2] << endl;
	cout << "String = " << ans << endl;
}

int main() {
	string a, b;

	cin >> a >> b;
	int n = a.length();
	int m = b.length();

	vector<vector<int>>dp(n, vector<int>(m, -1));

	cout << LCS(a, b, n, m, 0, 0, dp);
	cout << endl;

	LCS_bottomUp(a, b);
	return 0;
}