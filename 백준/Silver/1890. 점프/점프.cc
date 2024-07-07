#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int arr[101][101];
long long cache[101][101];
long long ans = 0;
long long dfs(int x, int y) {
	if (x >= n || y >= n || x<0 || y<0) {
		return 0;
	}
	if (x == n - 1 && y == n - 1) {
		return 1;
	}
	long long& ref = cache[y][x];
	if (ref != -1) {
		return ref;
	}
	int jump = arr[y][x];
	if (jump == 0) {
		return 0;
	}
	return ref = (dfs(x+jump, y) + dfs(x, y+jump));
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	dfs(0, 0);
	cout << cache[0][0];
	return 0;
}