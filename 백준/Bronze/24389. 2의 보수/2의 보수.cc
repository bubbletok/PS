#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using prl = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned int n; cin >> n;
	unsigned int t = ~n + 1;
	vector<int> v1,v2;
	for (int i = 32; i >= 0; i--)
	{
		unsigned int tmp1 = (n >> i) & 1;
		unsigned int tmp2 = (t >> i) & 1;
		v1.push_back(tmp1);
		v2.push_back(tmp2);
	}
	int ans = 0;
	for (int i = 0; i < 32; i++)
	{
		if (v1[i] != v2[i]) ans++;
	}
	cout << ans;
	return 0;
}