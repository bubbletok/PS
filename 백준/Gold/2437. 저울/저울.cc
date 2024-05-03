#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n;
int arr[1001];
bool canEstimate[1000001] = { false };
vector<int> weights;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	int last = arr[0];
	bool found = last == 1 ? false : true;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if(found) break;
		if(!(arr[i]+1 <= last+1 && last+1 <= arr[i]+last) && last+1!=arr[i]){
			break;
		}
		last = arr[i]+last;
		ans = last+1;
	}
	cout << ans;
	return 0;
}