#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int n;
int fr[10] = { 0 };
int ans = 0;
bool check() {
	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		if (fr[i] > 0) cnt++;
	}
	return (cnt <= 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int s = 0, e = 0;
	fr[v[0]]++;
	while (s<n&&e<n) {
		if (check()) {
			ans = max(ans, (e - s) + 1);
			e++;
			if(e<n) fr[v[e]]++;
		}
		else {
			fr[v[s]]--;
			s++;
		}
	}
	cout << ans;
	return 0;
}