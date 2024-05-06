#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
vector<int> v[101];
int dist[101][101] = {{0,}};

void bfs(int start, bool* check){
	queue<pair<int,int>> q;
	check[start] = true;
	dist[start][start] = 0;
	q.push({start,0});
	while(!q.empty()){
		int cur_user = q.front().first;
		int cur_dist = q.front().second;
		q.pop();
		for(int i=0; i<v[cur_user].size(); i++){
			int next_user = v[cur_user][i];
			int next_dist = cur_dist+1;
			if(check[next_user]) continue;
			dist[start][next_user] = next_dist;
			check[next_user] = true;
			q.push({next_user,next_dist});
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1; i<=n; i++){
		bool check[101];
		memset(check,false,sizeof(check));
		bfs(i,check);	
	}
	int min = 999999999;
	int min_user = 1;
	for(int i=1; i<=n; i++){
		int sum = 0;
		for(int j=1; j<=n; j++){
			sum += dist[i][j];
		}
		if(sum<min){
			min = sum;
			min_user = i;
		}
	}
	cout << min_user;
	return 0;
}