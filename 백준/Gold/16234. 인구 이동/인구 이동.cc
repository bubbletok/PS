#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;
int n, l, r;
int arr[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = 0;
bool bfs(int x, int y, bool check[101][101], vector<pair<vector<pair<int,int>>, int>>& v) {
	//cout << "x: " << x << ", y: " << y << endl;
	check[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	int sum = arr[y][x];
	vector<pair<int, int>> cty;
	cty.push_back({ x,y });
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !check[ny][nx]) {
				int dif = abs(arr[ny][nx] - arr[fy][fx]);
				//cout << dif << endl;
				if (l <= dif && dif <= r) {
					//cout << nx << " " << ny << endl;
					q.push({ nx,ny });
					sum += arr[ny][nx];
					cty.push_back({ nx, ny });
					check[ny][nx] = true;
				}
			}
		}
	}
	if (cty.size() == 1) return false;
	int avg = sum / (int)cty.size();
	v.push_back({ cty, avg });
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int a = 0; a < n*n; a++) {
		bool found = false;
		bool check[101][101];
		vector<pair<vector<pair<int,int>>, int>> v;
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j]) continue;
				if (bfs(j, i, check, v)) {
					found = true;
				}
			}
		}
		if (!found) break;
		for (int i = 0; i < v.size(); i++) {
			int avg = v[i].second;
			for (int j = 0; j < v[i].first.size(); j++) {
				int x = v[i].first[j].first;
				int y = v[i].first[j].second;
				arr[y][x] = avg;
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}