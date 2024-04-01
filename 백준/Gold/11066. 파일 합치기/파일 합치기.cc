#include <iostream>
#include <algorithm>
using namespace std;
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[501];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int sums[501] = { 0 };
		sums[0] = arr[0];
		for (int i = 1; i < n; i++) {
			sums[i] = sums[i - 1] + arr[i];
		}

		int dp[501][501] = { {0,} };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) dp[i][j] = arr[i];
				else dp[i][j] = 0;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			dp[i][i + 1] = arr[i] + arr[i + 1];
			for (int j = i + 2; j < n; j++) {
				int prefix = (sums[j] - sums[i] + arr[i]);
				for (int k = i, l=i+1; k < j; k++,l++) {
					int left = dp[i][k];
					int down = dp[l][j];
					//cout << "i: " << i << ", j: " << j << ", k: " << k << ", l: " << l << endl;
					//cout << left << " " << down << endl;
					if (k == i) {
						//cout << "k==0, " << down + prefix << endl;
						dp[i][j] = down + prefix;
					}
					else if (k == j - 1) {
						//cout << "k==j-1, " << left + prefix << endl;
						dp[i][j] = min(dp[i][j], left + prefix);
					}
					else {
						//cout << "k==" << k << ", " << (left+down+prefix) << endl;
						dp[i][j] = min(dp[i][j], (left + down + prefix));
					}
				}
			}
		}
		cout << dp[0][n - 1] << "\n";
	}
	return 0;
}