//Love Babbar DP
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	int list1[n];
	int list2[m];

	int ans = 0;

	for (int i = 0; i < n; i++)    cin >> list1[i];

	for (int i = 0; i < m; i++)    cin >> list2[i];

	for (int i = 0; i < n; i++) {
		int min_val = INT_MAX;
		for (int j = 0; j < m; j++) {
			if (list1[i] ^ list2[j] < min_val) {
				min_val = list2[j] ^ list1[i];
				cout << list1[i] << " " << list2[j] << endl;
			}
		}
		ans = ans | min_val;
	}
	cout << ans << endl;
	return 0;
}
