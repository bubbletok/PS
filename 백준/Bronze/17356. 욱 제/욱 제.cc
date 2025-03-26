#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <set>
#include <cassert>
#include <stack>
#include <cstring>
#include <map>
#include <unordered_map>
#include <cmath>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repi(i, n) for (ll i = 1; i <= (n); i++)
#define MAX 112312312312;
using namespace std;
using ll = long long;
using pr = pair<int, int>;
using prl = pair<ll, ll>;
vector<prl> graph[11];
ll n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	double m = (b - a)/400.0f;
	double p = 1.0f / (1 + pow(10, m));
	cout << p;
	return 0;
}