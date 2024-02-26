#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[101];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int ans = 1;
	for(int i=1; i<=6; i++){
		if(n>=pow(2,i)){
			ans = pow(2,i);
		}
	}
	cout << ans;
	return 0;
}