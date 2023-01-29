#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

int len(int n){
	int cnt = 1;
	while(n>=10){
		n/=10;
		cnt++;
	}
	return cnt;
}
using namespace std;
int main() {
	int n,m;
	bool arr[10];
	memset(arr,true,sizeof(bool[10]));
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a;
		cin >> a;
		arr[a] = false;
	}
	int cnt = 5000001;
	for(int i=0; i<=999999; i++){
		int l = len(i);
		int num[6], tmp = i;
		for(int j=0; j<l; j++){
			num[l-1-j] = tmp%10;
			tmp/=10;
		}
		bool check = true;
		for(int j=0; j<l; j++){
			if(!arr[num[j]]){
				check = false;
				break;
			}
		}
		if(check){
			cnt = min(cnt,abs(i-n)+l);
		}
	}
	cnt = min(cnt,abs(100-n));
	cout << cnt;
	return 0;
}