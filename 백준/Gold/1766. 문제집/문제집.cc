#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;
int n, m;
vector<pair<int,int>> v;
vector<int> graph[32001];
int cnt[32001];
bool check[32001];

void bfs(int s) {
	check[s] = true;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(s);
	stack<int> stk;
	while (!pq.empty()) {
		int f = pq.top();
		cout << f << " ";
		pq.pop();
		for (int i = 0; i < graph[f].size(); i++) {
			int next = graph[f][i];
			cnt[next]--;
			if (cnt[next] == 0) {
				pq.push(next);
				check[next] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		cnt[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] || cnt[i] != 0) continue;
		bfs(i);
	}
}