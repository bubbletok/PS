#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;
vector<pair<int,int>> graph[300001];
int n,m,k,x;
void dijkstra(int start, vector<int>& dist, vector<pair<int,int>>* graph){
	dist[start] = 0;
	priority_queue<pair<int,int>> q;
	q.push({0,start});
	while(!q.empty()){
		int cur_dist = -q.top().first;
		int cur_node = q.top().second;
		q.pop();
		
		for(int i=0; i<graph[cur_node].size(); i++){
			int new_node = graph[cur_node][i].first;
			int new_dist = cur_dist + graph[cur_node][i].second;
			//cout << new_node << " " << new_dist << endl;
			if(new_dist < dist[new_node]){
				dist[new_node] = new_dist;
				q.push({-new_dist,new_node});
			}
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
		graph[a].push_back({b,1});
	}
	vector<int> dist(n+1,INF);
	dijkstra(x,dist,graph);
	vector<int> ans;
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