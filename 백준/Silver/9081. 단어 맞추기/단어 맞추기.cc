#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string tmp = s;
		sort(tmp.begin(), tmp.end(), greater<char>());
		if (tmp == s) cout << tmp << "\n";
		else {
			next_permutation(s.begin(), s.end());
			cout << s << "\n";
		}
	}
	return 0;
}