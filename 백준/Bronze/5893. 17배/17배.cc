#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
using ll = long long;
using prl = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	deque<int> dq;
	for (auto i : s)
	{
		dq.push_back(i - '0');
	}
	for (int i = 0; i < n; i++)
	{
		dq[i] *= 17;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		dq[i - 1] += dq[i] / 2;
		dq[i] %= 2;
	}
	while (dq.front() >= 2) {
		int a = dq.front();
		dq[0] %= 2;
		dq.push_front(a / 2);
	}
	for (auto i : dq)
		cout << i;
	return 0;
}