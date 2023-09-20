#include <iostream>
#include <vector>
using namespace std;
vector<int> v[51];
bool check[51] = {false};
int leap = 0;
void f(int n){
	check[n] = false;
	for(int i=0; i<v[n].size(); i++)
	{
		f(v[n][i]);
	}
}

void dfs(int next){
	if(!check[next]) return;
	bool has = false;
	for(int i=0; i<v[next].size(); i++){
		if(check[v[next][i]]){
			has = true;
			break;
		}
	}
	if(!has){
		leap++;
		return;
	}
	for(int i=0; i<v[next].size(); i++){
		if(check[v[next][i]])
			dfs(v[next][i]);
	}
}

int main() {
	int n;
	cin >> n;
	int root = 0;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(a==-1)
			root = i;
		else{
			v[a].push_back(i);
		}
		check[i] = true;
	}
	int e;
	cin >> e;
	f(e);
	dfs(root);
	cout << leap;
	return 0;
}