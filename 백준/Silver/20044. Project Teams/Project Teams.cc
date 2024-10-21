#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	cin >> n;
	vector<int> vec(2*n, -1);
	for (int i = 0; i < n*2; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(),vec.end());
	int min = 1000000000;
	for (int i = 0; i < n; i++) {
		if (min > vec[n + i] + vec[n - i - 1]) {
			min = vec[n + i] + vec[n - i - 1];
		}
	}
	cout << min;
}