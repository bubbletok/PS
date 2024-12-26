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
	int a, b, c; cin >> a >> b >> c;
	int n; cin >> n;
	bool check = false;
	for (int i = 0; a * i <= n; i++) {
		for (int j = 0; b * j <= n; j++) {
			for (int k = 0; c * k <= n; k++) {
				int tmp = a * i + b * j + c * k;
				if (tmp == n) {
					check = true;
					break;
				}
			}
			if (check) break;
		}
		if (check) break;
	}
	if (check) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}