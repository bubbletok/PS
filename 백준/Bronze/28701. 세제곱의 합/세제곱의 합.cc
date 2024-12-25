#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 1; i <= n; i++) {
		sum1 += i;
		sum2 += i;
		sum3 += i*i*i;
	}
	sum2 = sum2 * sum2;
	cout << sum1 << endl << sum2 << endl << sum3 << endl;
	return 0;
}