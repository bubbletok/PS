#include <iostream>
#include <queue>
using namespace std;
int n,m, arr[101][101];
bool check[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y){
	check[x][y] = true;
	for(int i=0; i<4; i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx >= 0 && yy >= 0 && !check[xx][yy] && arr[xx][yy]){
			dfs(xx,yy);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int cnt = 0,k;
		cin >> n >> m >> k;
		for(int j=0; j<m; j++){
			for(int jj=0; jj<n; jj++){
				check[jj][j] = false;
				arr[jj][j] = 0;
			}
		}
		for(int j=0; j<k; j++){
			int a,b;
			cin >> a >> b;
			arr[b][a] = 1;
		}
		for(int j=0; j<n; j++){
			for(int jj=0; jj<m; jj++){
				if(!check[jj][j] && arr[jj][j]){
					dfs(jj,j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}