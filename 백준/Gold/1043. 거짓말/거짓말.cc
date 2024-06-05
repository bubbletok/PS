#include <iostream>
#include <algorithm>
using namespace std;
int parent[51];
int truth[51];
int party[51][51];
int t;
int partyNum[51];
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

bool areUnion(int x){
	for(int i=0; i<t; i++){
		if(!isUnion(truth[i],x)) return false;
	}
	return (t!=0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		parent[i] = i;
	}
	
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> truth[i];
	}
	sort(truth,truth+t);
	for(int i=1; i<t; i++){
		merge(truth[0],truth[i]);
	}
	
	int ans = 0;
	for(int i=0; i<m; i++){
		int a;
		cin >> a;
		partyNum[i] = a;
		for(int j=0; j<a; j++){
			cin >> party[i][j];
		}
		sort(party[i],party[i]+a);
		for(int j=1; j<a; j++){
			if(j!=0){
				merge(party[i][0],party[i][j]);
			}
		}
	}
	for(int i=0; i<m; i++){
		bool canParty = true;
		for(int j=0; j<partyNum[i]; j++){
			canParty = !areUnion(party[i][j]);
			if(!canParty) break;
		}
		if(canParty) ans++;
	}
	cout << ans;
	return 0;
}