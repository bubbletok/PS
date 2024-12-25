#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		while (tmp != 0) {
			int x = tmp % 10;
			if (x == 3 || x == 6 || x == 9) ans++;
			tmp /= 10;
		}
	}
	cout << ans;
	return 0;
}