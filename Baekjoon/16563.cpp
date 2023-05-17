#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	bool isPrime[5000001];
	memset(isPrime,true,5000000);
	isPrime[1] = false;
	for(int i=2; i*i<=5000000; i++){
		for(int j=i*2; j<=5000000; j+=i){
			isPrime[j] = false;
		}
	}
	vector<int> primes;
	for(int i=1; i<=5000000; i++){
		if(isPrime[i]) primes.push_back(i);
	}
	for(int i=0; i<n; i++){
		int k;
		cin >> k;
		for(int j=0; j<primes.size(); j++){
			if(k==1) break;
			if(isPrime[k]){
				cout << k;
				break;
			}
			while(k%primes[j]==0){
				cout << primes[j] << " ";
				k /= primes[j];
			}
		}
		cout << "\n";
	}
	return 0;
}