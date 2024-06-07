#include <iostream>
using namespace std;
int arr[1000001];
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, max = 0;
	cin >>n;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		max = a > max ? a : max;
		arr[a-1]++;
	}
	for(int i=0; i<max; i++){
		for(int j=0; j<arr[i]; j++){
			if(arr[i]!=0)
				cout << i+1 << "\n";
		}
	}
	return 0;
}