#include <iostream>
using namespace std;
using ll = long long;
using prl = pair<ll, ll>;

 int ccw(prl a, prl b, prl c)
 {
	 ll outer = a.first * b.second + b.first * c.second + c.first * a.second;
	 outer -= a.first * c.second + b.first * a.second + c.first * b.second;
	 if (outer > 0) return 1;
	 if (outer < 0) return -1;
	 return 0;
 }

 void isIntersect(prl a, prl b, prl c, prl d)
 {
	 int abc = ccw(a, b, c);
	 int abd = ccw(a, b, d);
	 int cda = ccw(c, d, a);
	 int cdb = ccw(c, d, b);

	 if (abc*abd < 0 && cda*cdb < 0) cout << 1;
	 else cout << 0;
 }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	prl a, b, c, d;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	cin >> d.first >> d.second;

	isIntersect(a, b, c, d);

	return 0;
}