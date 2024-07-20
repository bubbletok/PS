#include <iostream>
#include <string.h>
#define MAX 1300000
using namespace std;
using ll = long long;
int t, k;
bool isPrime[MAX+1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	isPrime[1] = false;
	for (int i = 2; i <= MAX; i++) isPrime[i] = true;
	for (int i = 2; i * i <= MAX; i++) {
		for (int j = i * 2; j <= MAX; j += i) {
			isPrime[j] = false;
		}
	}
	cin >> t;
	while (t--) {
		int k; cin >> k;
		if (isPrime[k]) cout << "0\n";
		else {
			bool left = false, right = false;
			int li = k - 1, lr = k + 1;
			while (li >= 0) {
				if (isPrime[li]) break;
				li--;
			}
			while (lr <= MAX) {
				if (isPrime[lr]) break;
				lr++;
			}
			cout << lr - li << "\n";
		}
	}
	return 0;
}