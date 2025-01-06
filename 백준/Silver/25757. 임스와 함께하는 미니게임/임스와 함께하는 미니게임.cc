#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
using pr = pair<int, int>;
int n;
char c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> c;
	set<string> p;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		p.insert(s);
	}
	int len = p.size();
	int ans = 0;
	if (c == 'Y') ans = len;
	else if (c == 'F') ans = len / 2;
	else if (c == 'O') ans = len / 3;
	cout << ans;
	return 0;
}