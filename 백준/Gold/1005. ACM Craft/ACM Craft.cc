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
int t;
int n, k, w;
void bfs(int start, vector<int> graph[], bool* visit, int* cost, int* newCost, int* degree) {
	visit[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int i = 0; i < graph[f].size(); i++) {
			int next = graph[f][i];
			degree[next]--;
			newCost[next] = max(newCost[next], cost[next] + newCost[f]);
			if (visit[next]) continue;
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
	cin >> t;
	while (t--) {
		vector<int> graph[1001];
		bool visit[1001] = { false };
		int cost[1001] = { 0 };
		int degree[1001] = { 0 };
		int newCost[1001] = { 0 };
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> cost[i]; newCost[i] = cost[i];
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			degree[y]++;
		}
		cin >> w;
		for (int i = 1; i <= n; i++) {
			if (visit[i] || degree[i] != 0) continue;
			bfs(i,graph,visit,cost,newCost,degree);
		}
		cout << newCost[w] << "\n";
	}
	return 0;
}