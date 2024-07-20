#include <iostream>
#include <string.h>
using namespace std;
using ll = long long;
int n, m;
int arr[501][501];
int cache[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	int& ref = cache[y][x];
	if (ref != -1) return ref;
	//cout << x << " " << y << endl;
	int tmp = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
		if (arr[y][x] <= arr[ny][nx]) continue;
		tmp += dfs(nx, ny);
		//ref = (ref == -1) ? tmp : ref + tmp;
	}
	return ref = tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << cache[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	cout << cache[0][0];
	return 0;
}