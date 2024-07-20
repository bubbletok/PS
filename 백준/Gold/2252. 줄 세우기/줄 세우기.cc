#include <iostream>
#include <string.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#define MAX 10001
#define INF 987654321
using namespace std;
using ll = long long;
int n, m;
vector<int> graph[32001];
int degree[32001];
bool visit[32001];
vector<int> ans;

void bfs(int start) {
	queue<int> q;
	visit[start] = true;
	q.push(start);
	while (!q.empty()) {
		int f = q.front();
		ans.push_back(f);
		q.pop();
		for (int i = 0; i < graph[f].size(); i++) {
			int next = graph[f][i];
			degree[next]--;
			if (degree[next] == 0) {
				q.push(next);
				visit[next] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
		degree[a]++;
	}
	for (int i = 1; i <= n; i++){
		int size = degree[i];
		if (visit[i] || size!=0) continue;
		bfs(i);
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	return 0;
}