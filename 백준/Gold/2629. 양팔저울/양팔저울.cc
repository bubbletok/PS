#include <iostream>
#include <stack>
#include <map>
using namespace std;
using ll = long long;
int w[31];
bool dp[31][15001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	
	for (int i = 1; i <= n; i++) dp[i][w[i]] = true;

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= 15000; k++) {
			dp[i][k] = dp[i][k] || dp[i - 1][abs(k - w[i])];
			dp[i][k] = dp[i][k] || dp[i - 1][k + w[i]];
			dp[i][k] = dp[i][k] || dp[i - 1][k];
		}
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (x > 15000) {
			cout << "N ";
		}
		else {
			bool tmp = false;
			for (int i = 1; i <= 30; i++) {
				if (dp[i][x]) {
					tmp = true;
					break;
				}
			}
			if (tmp) cout << "Y ";
			else cout << "N ";
		}
	}
}