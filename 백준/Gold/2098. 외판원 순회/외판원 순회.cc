#include <iostream>
#include <string.h>
using namespace std;
using ll = long long;
int w[17][17];
int dp[17][1 << 16];
int n;

int dfs(int cur, int state) {
	int& ret = dp[cur][state];
	// 이미 처리한 경우
	if (~ret) return ret;

	// 모든 노드 탐색한 경우
	if (state == ((1 << n) - 1)) {
		// 다시 원점으로 되돌아가기
		if (w[cur][0] != 0) return w[cur][0];
		// 돌아갈 수 없으면 불가능한 경우
		return 1e9;
	}

	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		// 방문했거나 갈 수 없는 경우
		if (state & (1 << i) || w[cur][i] == 0) continue;
		// cur->i로 간 이후 i->?로 가는 경우 계산
		ans = min(ans, w[cur][i] + dfs(i, state | (1 << i)));
	}
	return ret = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	int ans = dfs(0, 1);
	cout << ans;
}