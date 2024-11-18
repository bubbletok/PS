#include <iostream>
#include <tuple>
#include <queue>
#include <string.h>
#define INF 100000000
using namespace std;
using ll = long long;
int n;
int arr[17][17];
int cnt[17][17];

bool check(int x, int y, int dir) {
	bool tmp = (x<n&&y<n&&arr[y][x]==0);
	if (dir == 2) {
		tmp = tmp && arr[y - 1][x] == 0 && arr[y][x - 1] == 0;
	}
	return tmp;
}

void solve(int x, int y, int dir) {
	if (!check(x, y, dir)) return;
	cnt[y][x]++;
	int nx = x + 1, ny = y + 1;
	if (dir == 0) {
		solve(nx, y, 0);
		solve(nx, ny, 2);
	}
	else if (dir == 1) {
		solve(x, ny, 1);
		solve(nx, ny, 2);
	}
	else if (dir == 2) {
		solve(nx, y, 0);
		solve(x, ny, 1);
		solve(nx, ny, 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(1, 0, 0);
	cout << cnt[n - 1][n - 1];
}