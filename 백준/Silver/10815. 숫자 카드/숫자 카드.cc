#include <iostream>
#include <algorithm>
using namespace std;
int arr[500001];

int binary_search(int a, int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		if(arr[mid] == a){
			return 1;
		}
		else if(arr[mid] > a){
			return binary_search(a,left,mid-1);
		}
		else
			return binary_search(a,mid+1,right);
	}
	else if(arr[left] == a)
		return 1;
	else
		return 0;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,m;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	cin >> m;
	for(int i=0; i<m; i++){
		int a;
		cin >> a;
		if(binary_search(a,0,n-1))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	return 0;
}