#include <iostream>
using namespace std;

#define int long long

int solve(int n)
{
	int dp[n + 1][8];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 8; j++)    dp[i][j] = 0;

	dp[0][7] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][0] += dp[i - 1][7];
		dp[i][1] += dp[i - 1][6];

		dp[i][3] += dp[i - 1][7];
		dp[i][3] += dp[i - 1][4];

		dp[i][4] += dp[i - 1][3];

		dp[i][6] += dp[i - 1][7];
		dp[i][6] += dp[i - 1][1];

		dp[i][7] += dp[i - 1][3];
		dp[i][7] += dp[i - 1][6];
		dp[i][7] += dp[i - 1][0];
	}
	return dp[n][7];
}

int32_t main()
{
	int n;
	cin >> n;
	if (n % 2 == 1)    cout << 0;
	else
		cout << solve(n);
	return 0;
}