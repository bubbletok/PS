#include <iostream>
#include <vector>
#include <string.h>
#define INF 1000000000
using namespace std;
using ll = long long;
vector<int> graph[1000001];
int n;
int dp[1000001][2];

void dfs(int parent, bool* check) {
	check[parent] = true;
	for (int i = 0; i < graph[parent].size(); i++) {
		int child = graph[parent][i];
		if (check[child]) continue;
		dfs(child, check);
		dp[parent][0] += dp[child][1];
		dp[parent][1] += min(dp[child][0], dp[child][1]);
	 }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}
	int ans = INF;
	for (int i = 1; i <= 1; i++) {
		bool check[1000001] = { false };
		dfs(i, check);
		ans = min(ans, min(dp[i][0], dp[i][1]));

	}
	cout << ans;
}