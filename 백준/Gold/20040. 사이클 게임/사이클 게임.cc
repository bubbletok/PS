#include <iostream>
using namespace std;
int parent[500001];

int find(int x){
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	parent[y] = x;
}

bool isUnion(int x, int y){
	x = find(x);
	y = find(y);
	return (x==y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i=0; i<n; i++){
		parent[i] = i;
	}
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		if(a>b){
			int tmp = a;
			a = b;
			b = tmp;
		}
		if(isUnion(a,b)){
			ans = i+1;
			break;
		}
		merge(a,b);
	}
	cout << ans;
	return 0;
}