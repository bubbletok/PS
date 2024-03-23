#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int m,n,x,y;
		cin >> m >> n >> x >> y;
		int i;
		bool found = false;
		for(i=x; i<=m*n; i+=m){
			if((i-1)%n + 1==y){
				found = true;
				break;
			}
		}
		if(!found) i = -1;
		
		cout << i << "\n";
	}
	return 0;
}