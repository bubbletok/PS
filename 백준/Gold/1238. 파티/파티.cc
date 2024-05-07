#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;
vector<pair<int,int>> graph[1001];
int n,m,x;
void dijkstra(int start, vector<int>& dist){
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
	cin >> n >> m >> x;
	for(int i=0; i<m; i++){
		int a,b,t;
		cin >> a >> b >> t;
		graph[a].push_back({b,t});
	}
	int ans = -1;
	vector<int> backDist(n+1,INF);
	dijkstra(x,backDist);
	for(int i=1; i<=n; i++){
		vector<int> dist(n+1, INF);
		dijkstra(i, dist);
		ans = dist[x]+backDist[i] > ans ? dist[x]+backDist[i] : ans;
	}
	cout << ans;
	return 0;
}