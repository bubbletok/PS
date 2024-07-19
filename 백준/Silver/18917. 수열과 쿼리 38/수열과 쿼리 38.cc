#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
using ll = long long;
int m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll sum = 0;
	ll xo = 0;
	cin >> m;
	while (m--) {
		int o;
		cin >> o;
		if (o == 1 || o == 2) {
			ll x;
			cin >> x;
			if (o == 1) {
				sum += x;
				xo ^= x;
			}
			else {
				sum -= x;
				xo ^= x;
			}
		}
		else if(o==3){
			cout << sum << "\n";
		}
		else if (o == 4) {
			cout << xo << "\n";
		}
	}
	return 0;
}