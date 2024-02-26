#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[1001];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	int time = 0, sum = 0;
	for(int i=0; i<n; i++){
		time += arr[i];
		sum += time;
	}
	cout << sum;
	return 0;
}