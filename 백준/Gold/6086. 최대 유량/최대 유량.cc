#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 987654321;
#define MAX 52
using namespace std;
using ll = long long;
int n;
int cap[MAX][MAX];
int flo[MAX][MAX];
vector<int> graph[MAX];

int toInt(char a) {
	int c = 0;
	if ('A' <= a && a <= 'Z') {
		c = a - 'A';
	}
	else {
		c = a - 'a' + 26;
	}
	return c;
}

int networkFlow(int start, int end) {
	int totalFlow = 0;
	while (true) {
		vector<int> parent(MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty() && parent[end] == -1) {
			int cur = q.front(); q.pop();
			for (int i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i];
				// 잔여 용량 남아있는가 && 아직 방문 안했는가
				if ((cap[cur][next] - flo[cur][next]) > 0 &&
					parent[next] == -1) {
					//cout << here << " " << there << endl;
					q.push(next);
					parent[next] = cur;
				}
			}
		}
		// 증가 경로가 없으면 반환한다.
		// cout << parent[end] << endl;
		if (parent[end] == -1) break;

		// 증가 경로를 통해 유량을 얼마나 보낼지 결정한다.
		int amount = INF;
		for (int p = end; p != start; p = parent[p]) {
			// 보낼 유량은 경로 중 가장 잔여 용량이 적은 것
			amount = min(cap[parent[p]][p] - flo[parent[p]][p], amount);
		}
		for (int p = end; p != start; p = parent[p]) {
			flo[parent[p]][p] += amount;
			flo[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	memset(cap, 0, sizeof(cap));
	memset(flo, 0, sizeof(flo));
	for (int i = 0; i < n; i++) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		int ai = toInt(a);
		int bi = toInt(b);
		//cout << ai << " " << bi << endl;
		graph[ai].push_back(bi);
		graph[bi].push_back(ai);
		cap[ai][bi] += c;
		cap[bi][ai] += c;
	}
	int ans = networkFlow(0, 25);
	cout << ans;
	return 0;
}