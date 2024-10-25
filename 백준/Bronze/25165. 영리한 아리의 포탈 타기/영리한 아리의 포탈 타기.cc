#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	cin >> n >> m;
	int a, d;
	cin >> a >> d;
	int sr, sc; cin >> sr >> sc;
	bool check = true;
	int cx = a, cy = 1;
	while (1) {
		if (cx == sc && cy == sr) {
			check = false;
			break;
		}
		if (cx == m && cy == n) {
			break;
		}
		cx += (d == 0) ? -1 : 1;
		if (cx == 0 || cx == m+1) {
			cx -= (d == 0) ? -1 : 1;
			cy++;
			d = d == 0 ? 1 : 0;
		}

	}
	if (check) cout << "YES!";
	else cout << "NO...";
}