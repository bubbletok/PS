#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int arr[101];
int dp[100001];
int ans = 1000001;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) dp[i] = 1000001;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - arr[j] <= 0) continue;
			dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}
	}
	ans = dp[k];
	if (ans == 1000001) ans = -1;
	cout << ans;
}