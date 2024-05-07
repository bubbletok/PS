#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;
vector<int> graph[300001];
int n,m,k,x;
vector<int> dist(300000+1,INF);
vector<int> ans;
bool check[300001] = {false};

void dfs(int start){
	queue<pair<int,int>> q;
	check[start]=true;
	q.push({start,0});
	while(!q.empty()){
		int node = q.front().first;
		int cur_dist = q.front().second;
		q.pop();
		dist[node] = cur_dist;
		for(int i=0; i<graph[node].size(); i++){
			int next = graph[node][i];
			if(check[next]) continue;
			q.push({next,cur_dist+1});
			check[next] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k >> x;
	for(int i=0; i<m; i++){
		int a,b,t;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	dfs(x);
	for(int i=1; i<=n; i++){
		if(dist[i]==k){
			ans.push_back(i);
		}
	}
	if(!ans.empty()){
		for(int i=0; i<ans.size(); i++){
			cout << ans[i] << "\n";
		}
	}
	else{
		cout << -1;
	}
	return 0;
}