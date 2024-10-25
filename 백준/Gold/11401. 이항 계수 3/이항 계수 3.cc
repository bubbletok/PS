#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
ll m = 1000000007;

ll pow(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return n%m;
	ll tmp = pow(n, k / 2) % m;
	if (k % 2 == 0) return (tmp%m * tmp%m) % m;
	else return ((tmp%m * tmp%m) * n % m) % m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	ll n, k; cin >> n >> k;
	//B^(P-2) === B^-1 (mod P)
	//AB^-1%P = AB^(P-2)%P = (A%P) * (B^(P-2)%P) % P
	ll A = 1;
	for (int i = 1; i <= n; i++) A = (A * i) % m;
	ll B = 1;
	for (int i = 1; i <= k; i++) B = (B * i) % m;
	ll BB = 1;
	for (int i = 1; i <= n - k; i++) BB = (BB * i) % m;
	B = (B % m * BB % m) % m;
	B = pow(B, m - 2) % m;
	cout << (A%m * B%m) % m;
}