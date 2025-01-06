#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
using ll = long long;
using pr = pair<int, int>;
ll n;
ll arr[100001];
ll sum[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sum[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arr[i] * (sum[n - 1] - sum[i]);
	}
	cout << ans;
	return 0;
}