#include <iostream>
using namespace std;
int arr[201];
int plan[1001];

int find(int x){
	if(arr[x] == x){
		return x;
	}
	return arr[x] = find(arr[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	arr[y] = x;
}

bool isUnion(int x, int y){
	x = find(x);
	y = find(y);
	return (x==y);
}

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	for(int i=1; i<=n; i++){
		arr[i] = i;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int a;
			cin >> a;
			if(a==1){
				merge(j,i);
			}
		}
	}
	for(int i=0; i<m; i++){
		cin >> plan[i];
	}
	for(int i=0; i<m-1; i++){
		if(!isUnion(plan[i],plan[i+1])){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}