#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int n, m;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> s;
	int r = m;
	ll ans = 0;
	int len = (n + 1) + n;
	for (int i = 0; i < m-len+1; i++) {
		if (s[i] == 'O') continue;
		bool found = true;
		int idx = i;
		for (int j = i; j < i + len-1; j++) {
			if (s[j] == s[j + 1]) {
				found = false;
				break;
			}
			idx = j;
		}
		if (found) {
			//cout << "i: " << i << endl;
			ans++;
		}
		else {
			i = idx;
		}
	}
	cout << ans;
	return 0;
}