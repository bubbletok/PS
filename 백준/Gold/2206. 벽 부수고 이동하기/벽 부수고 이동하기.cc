#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;
int n, m;
char arr[1001][1001];
bool check[1001][1001][2]; // 벽을 뚫고 간 길인지, 그냥 간 길인지 구분
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = 10000000;
void bfs(int x, int y, int ex, int ey) {
	check[y][x][0] = true;
	check[y][x][1] = true;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {x,y},{1,1} });
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int fb = q.front().second.first;
		int fc = q.front().second.second;
		q.pop();
		if (fx == ex && fy == ey) {
			ans = min(ans, fc);
		}
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			int nc = fc + 1;
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (fb == 1 && arr[ny][nx] == '1' && !check[ny][nx][0]) {
					q.push({ {nx,ny} ,{0,nc} });
					check[ny][nx][0] = true;
					//cout << nx << " " << ny << endl;
				}
				else if (arr[ny][nx] == '0' && !check[ny][nx][fb]) {
					q.push({ {nx,ny}, {fb,nc} });
					check[ny][nx][fb] = true;
					//cout << nx << " " << ny << endl;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	memset(check, false, sizeof(check));
	bfs(0, 0, m - 1, n - 1);
	memset(check, false, sizeof(check));
	bfs(m - 1, n - 1, 0, 0);
	ans = ans == 10000000 ? -1 : ans;
	cout << ans;
	return 0;
}