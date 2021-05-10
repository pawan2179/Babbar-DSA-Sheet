#include<bits/stdc++.h>
using namespace std;

int main() {

	string str;
	cin >> str;

	int n = str.length();
	int table[n][n];
	int max_length = 1;
	int start = 0;

	memset(table, 0, sizeof(table));

	for (int i = 0; i < n; i++)    table[i][i] = 1;

	for (int i = 0; i < n - 1; i++)
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = 1;
			max_length = 2;
			start = i;
		}

	for (int k = 3; k <= n; k++) {
		for (int i = 0; i < n - k + 1; i++) {
			int j = i + k - 1;

			if (table[i + 1][j - 1] == 1 and str[i] == str[j]) {
				table[i][j] = true;
				if (k > max_length) {
					max_length = k;
					start = i;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)    cout << table[i][j] << " ";
		cout << endl;
	}
	cout << "Max length = " << max_length << endl;
	cout << "Substring = " << str.substr(start, start + max_length) << endl;
	return 0;
}