#include <iostream>
using namespace std;

int main() {
	int n, dis[100001], price[100001];
	long long int sum = 0;
	cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> dis[i];
	}
	for(int i=0; i<n; i++){
		cin >> price[i];
	}
	for(int i=0; i<n; i++){
		int skip = 0;
		long long int sumDis = dis[i];
		for(int j=i+1; j<n-1; j++){
			if(price[i] < price[j]){
				sumDis += dis[j];
				skip++;
			}
			else
				break;
		}
		sum += 1LL*price[i]*sumDis;
		i += skip;
	}
	cout << sum;
	return 0;
}