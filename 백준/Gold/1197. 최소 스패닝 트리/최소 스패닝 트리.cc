#include <iostream>
#include <string.h>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX 10001
using namespace std;
using ll = long long;
int v, e;
vector<pair<int, int>> graph[MAX];
vector<tuple<int,int,int>> edges;
int parent[MAX];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);  y = find(y);
	if (x == y) return;
	parent[y] = x;
}

bool isUnion(int x, int y) {
	x = find(x); y = find(y);
	return (x == y);
}

int kruskal() {
	int ret = 0;
	for (int i = 0; i < edges.size(); i++) {
		int cost = get<0>(edges[i]);
		int u = get<1>(edges[i]), v = get<2>(edges[i]);
		if (isUnion(u, v)) continue;
		merge(u, v);
		ret += cost;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e;
	for (int i = 1; i <= v; i++) parent[i] = i;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end());
	int ans = kruskal();
	cout << ans;
	return 0;
}