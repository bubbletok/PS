#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long int arr[100001];
	for(int i = 0; i<n; i++) cin >> arr[i];
	long long int x;
	cin >> x;
	int ans = 0;
	int s=0,e=n-1;
	sort(arr,arr+n);
	while(s<e){
		if(arr[s]+arr[e]==x){
			ans++;
		}
		if(arr[s]+arr[e]>=x){
			e--;
		}
		else{
			s++;
		}
	}
	cout << ans;
	return 0;
}