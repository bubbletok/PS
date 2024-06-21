#include <iostream>
#include <algorithm>
using namespace std;
int arr[2001];
int ser[2001];

int binary_search(int n, int seek){
	int start = 0, end = n-1;
	while(start<=end){
		int mid = (start+end)/2;
		if(arr[mid]==seek){
			return mid;
		}
		if(arr[mid]>seek){
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	return -1;
}

bool isGood(int n, int idx, int val){
	for(int i=0; i<n-1; i++){
		if(i==idx) continue;
		for(int j=i+1; j<n; j++){
			if(j==idx) continue;
			//cout << arr[i] << " " << arr[j] << endl;
			if(arr[i]+arr[j]>val){
				break;
			}
			if(arr[i]+arr[j] == val){
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=0; i<n; i++){
		ser[i] = arr[i];
	}
	sort(arr,arr+n);
	
	int ans = 0;
	for(int i=0; i<n; i++){
		int idx = binary_search(n,ser[i]);
		if(isGood(n,idx,ser[i])){
			ans++;
		}
		//cout << endl;
	}
	cout << ans;
	return 0;
}