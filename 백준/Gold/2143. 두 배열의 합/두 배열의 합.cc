#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long a[1001];
long long prefixA[1001];
long long b[1001];
long long prefixB[1001];
long long ans = 0;
vector<long long> subA;
vector<long long> subB;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// Calculate the prefix sum of a
	prefixA[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefixA[i] = prefixA[i - 1] + a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	// Calculate the prefix sum of b
	prefixB[0] = b[0];
	for (int i = 1; i < m; i++) {
		prefixB[i] = prefixB[i - 1] + b[i];
	}

	// Find all of sub-sums from preifx sum a
	// Total: n^2
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			long long sub = prefixA[j] - prefixA[i] + a[i];
			subA.push_back(sub);
		}
	}

	// Find all of usb-sums from prefix sum b
	// Total: m^2
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			long long sub = prefixB[j] - prefixB[i] + b[i];
			subB.push_back(sub);
		}
	}

	sort(subB.begin(), subB.end());
	//int tmp = 6;
	//cout << binary_search(subB.begin(), subB.end(), tmp) << endl;
	//cout << upper_bound(subB.begin(), subB.end(), tmp) - subB.begin() << endl;
	//cout << lower_bound(subB.begin(), subB.end(), tmp) - subB.begin() << endl;

	for (int i = 0; i < subA.size(); i++) {
		long long dif = t - subA[i];
		if (!binary_search(subB.begin(), subB.end(), dif)) continue;
		int upper = upper_bound(subB.begin(), subB.end(), dif) - subB.begin();
		int lower = lower_bound(subB.begin(), subB.end(), dif) - subB.begin();
		//cout << "dif: " << dif << " upper: " << upper << " lower: " << lower << endl;
		int cnt = upper - lower;
		/*if (upper == lower && subB[lower] == dif) cnt++;
		else if (subB[upper] == dif && subB[upper] == subB[upper - 1]) cnt++;
		*/
		ans += cnt;
	}
	cout << ans;
	return 0;
}