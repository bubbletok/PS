#include <iostream>
#include <queue>
using namespace std;
int n, m;
char arr[11][11];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool canGetoutRed = false;
int ans = -1;
pair<int, int> escape;
struct redball {
	int x;
	int y;
	bool fall;
};
struct blueball {
	int x;
	int y;
	bool fall;
};
void moveBlueBall(blueball& blue, redball& red, pair<int,int> dir) {
	while (1) {
		int nx = blue.x + dir.first;
		int ny = blue.y + dir.second;
		if (escape.first == nx && escape.second == ny) {
			blue.fall = true;
			blue.x = nx;
			blue.y = ny;
			break;
		}
		if (arr[ny][nx] == '#' || (nx == red.x && ny == red.y)) {
			break;
		}
		blue.x = nx;
		blue.y = ny;
	}
}

void moveRedBall(redball& red, blueball& blue, pair<int,int> dir) {
	while (1) {
		int nx = red.x + dir.first;
		int ny = red.y + dir.second;
		if (escape.first == nx && escape.second == ny) {
			red.fall = true;
			red.x = nx;
			red.y = ny;
			break;
		}
		if (arr[ny][nx] == '#' || (nx==blue.x && ny==blue.y)) {

			break;
		}
		red.x = nx;
		red.y = ny;
	}
}

void bfs(redball red, blueball blue) {
	queue<pair<pair<redball,blueball>, int>> q;
	q.push({ {red,blue},0 });
	while (!q.empty()) {
		redball fred = q.front().first.first;
		blueball fblue = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (cnt > 10 || (fred.fall && fblue.fall)) {
			continue;
		}
		if (fred.fall && !fblue.fall) {
			canGetoutRed = true;
			if (ans == -1) {
				ans = cnt;
			}
			else {
				ans = ans > cnt ? cnt : ans;
			}
			return;
		}

		for (int i = 0; i < 4; i++) {
			pair<int, int> dir = { dx[i],dy[i] };
			redball nred = fred;
			blueball nblue = fblue;
			if (i == 0) {
				if (nred.y < nblue.y) {
					moveRedBall(nred, nblue, dir);
					moveBlueBall(nblue,nred, dir);
				}
				else {
					moveBlueBall(nblue, nred, dir);
					moveRedBall(nred, nblue, dir);
				}
			}
			if (i == 1) {
				if (nred.y < nblue.y) {
					moveBlueBall(nblue, nred, dir);
					moveRedBall(nred, nblue, dir);
				}
				else {
					moveRedBall(nred, nblue, dir);
					moveBlueBall(nblue, nred, dir);
				}
			}
			if (i == 2) {
				if (nred.x < nblue.x) {
					moveRedBall(nred, nblue, dir);
					moveBlueBall(nblue, nred, dir);
				}
				else {
					moveBlueBall(nblue, nred, dir);
					moveRedBall(nred, nblue, dir);
				}
			}
			if (i == 3) {
				if (nred.x < nblue.x) {
					moveBlueBall(nblue, nred, dir);
					moveRedBall(nred, nblue, dir);
				}
				else {
					moveRedBall(nred, nblue, dir);
					moveBlueBall(nblue, nred, dir);
				}
			}
			if (nblue.fall) {
				continue;
			}
			if (nred.x == fred.x && nred.y == fred.y &&
				nblue.x == fblue.x && nblue.y == fblue.y) {
				continue;
			}
			q.push({ {nred,nblue},cnt + 1 });
		}
	}
}
int main() {
	redball red;
	blueball blue;
	red.fall = false, blue.fall = false;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				red.x = j, red.y = i;
			}
			if (arr[i][j] == 'B') {
				blue.x = j, blue.y = i;
			}
			if (arr[i][j] == 'O') {
				escape.first = j, escape.second = i;
			}
		}
	}
	bfs(red, blue);
	cout << ans;
	return 0;
}