#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	int* arr = new int[n*n+1], *tmp = new int[n*n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i*n+j];
			tmp[i*n+j] = arr[i*n+j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j==0){
				if(i!=0)
					tmp[i*n+j] += tmp[(i-1)*n+n-1];
			}
			else
				tmp[i*n+j] += tmp[i*n+j-1];
		}
	}
	for(int i=0; i<m; i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		int res = 0;
		if(x1==x2 && y1==y2)
			res = arr[x1*n+y1];
		else{
			res = tmp[x2*n+y2] - tmp[x1*n+y1] + arr[x1*n+y1];
			for(int i=x1; i<=x2; i++){
				int stn1 = y1 > y2 ? y1 : y2;
				int stn2 = y1 < y2 ? y1 : y2;
				if(y1 != n-1 && y2 != n-1){
					if(i != x2){
						res -= tmp[i*n+n-1] - tmp[i*n+stn1];
					}
				}
				if(y1 != 0 && y2 != 0){
					if(i != x1){
						res -= tmp[i*n+stn2-1] - tmp[i*n-1];
					}
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}