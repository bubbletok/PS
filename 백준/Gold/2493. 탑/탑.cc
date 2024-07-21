#include <iostream>
#include <stack>
#include <vector>
#define MAX 10001
#define INF 987654321
using namespace std;
using ll = long long;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	stack<pair<int, int>> s;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (s.empty()) {
			s.push({ a,i });
			ans.push_back(0);
		}
		else {
			while (!s.empty() && s.top().first < a) {
				s.pop();
			}
			if(!s.empty()){
				ans.push_back(s.top().second);
			}
			else {
				ans.push_back(0);
			}
			s.push({ a,i });
		}
	}
	for (auto i : ans) cout << i << " ";
	return 0;
}