#include <iostream>
#include <stack>
#include <map>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n; cin >> n;
	ll ans = 0;
	stack<int> s;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (s.empty()) {
			s.push(x);
			cnt[x]++;
			continue;
		}
		if (s.top() <= x) {
			while (!s.empty() && s.top() < x) {
				ans++;
				cnt[s.top()]--;
				s.pop();
			}
			ans += cnt[x];
			if(cnt[x]-s.size()>0) {
				ans++;
			}
			s.push(x);
			cnt[x]++;
		}
		else {
			ans++;
			s.push(x);
			cnt[x]++;
		}
	}
	cout << ans;
}