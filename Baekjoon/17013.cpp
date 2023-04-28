#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool p[1000001] = {false};
	for(int i=2; i<=1000000; i++){
		if(isPrime(i))
			p[i] = true;
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int cnt = 0;
		for(int i=2; i<=n/2; i++){
			if(p[i] && p[n-i]){
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}