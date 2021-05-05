#include<bits/stdc++.h>
using namespace std;

bool checkSubArraySum(int *arr, int m, int &start, int &end) {

	int sum[m] = {0};
	unordered_map<int, int> hashmap;
	hashmap[0] = -1;

	for (int i = 0; i < m; i++) {
		if (i == 0)    sum[i] = arr[i];
		else    sum[i] = sum[i - 1] + arr[i];
	}

	int max_len = 0;
	for (int i = 0; i < m; i++) {
		if (hashmap.find(sum[i]) == hashmap.end())    hashmap[sum[i]] = i;
		else {
			if (i - hashmap[sum[i]] > max_len) {
				max_len = i - hashmap[sum[i]];
				start = hashmap[sum[i]] + 1;
				end = i + 1;
			}
		}
	}
	if (max_len == 0)    return false;
	return true;
}

int main() {
	int n, m;

	cin >> n >> m;
	vector<vector<int>>arr(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)    arr[i][j] = -1;
		}

	int start_row = 0;
	int start_col = 0;
	int end_row = 0;
	int end_col = 0;

	int final_Top = 0;
	int final_Bottom = 0;
	int final_Left = 0;
	int final_Right = 0;

	int temp[m] = {0};
	int max_area = 0;

	for (int i = 0; i < n; i++) {
		memset(temp, 0, sizeof(temp));
		for (int j = i; j < n; j++) {
			for (int k = 0; k < m; k++)
				temp[k] += arr[j][k];
			if (checkSubArraySum(temp, m, start_col, end_col)) {
				int area = (j - i + 1) * (end_col - start_col);

				if (area > max_area) {
					final_Top = i;
					final_Bottom = j;
					final_Left = start_col;
					final_Right = end_col;
					max_area = area;
				}
			}
		}
	}

	cout << "Top --> " << final_Top << ", Bottom --> " << final_Bottom <<
	     ", Left --> " << final_Left << ", Right --> " << final_Right << endl;

	cout << max_area;
	return 0;
}