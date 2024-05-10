#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[2001];
int main() {
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int dp[2001];
	dp[0] = arr[0];
	int last = 0;
	int size = 1;
	for(int i=1; i<n; i++){
		int cur = 0;
		while(cur < size){
			if(dp[cur]<=arr[i]){
				break;
			}
			cur++;
		}
		if(cur==size) size++;
		dp[cur]=arr[i];
	}
	cout << n-size;
	return 0;
}