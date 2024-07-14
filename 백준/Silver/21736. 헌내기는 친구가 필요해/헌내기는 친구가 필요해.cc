#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
int n, m;
char cam[601][601];
bool check[601][601];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = 0;
void bfs(int x, int y) {
	check[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		if (cam[fy][fx] == 'P') {
			ans++;
		}
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n && !check[ny][nx]) {
				if (cam[ny][nx] != 'X') {
					check[ny][nx] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int sx = 0, sy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cam[i][j];
			if (cam[i][j] == 'I') {
				sx = j, sy = i;
			}
		}
	}
	bfs(sx, sy);
	if (ans == 0) {
		cout << "TT";
	}
	else {
		cout << ans;
	}
	return 0;
}