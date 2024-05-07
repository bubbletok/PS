#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;
vector<pair<int,long long>> graph[1001];
int n,m,x;
void dijkstra(int start, vector<long long>& dist){
	dist[start] = 0;
	priority_queue<pair<int,long long>> q;
	q.push({0,start});
	while(!q.empty()){
		int cur_dist = -q.top().first;
		int cur_node = q.top().second;
		q.pop();
		for(int i=0; i<graph[cur_node].size(); i++){
			int new_node = graph[cur_node][i].first;
			long long new_dist = cur_dist + graph[cur_node][i].second;
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
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a,b,t;
		cin >> a >> b >> t;
		graph[a].push_back({b,t});
		graph[b].push_back({a,t});
	}
	int v1, v2;
	cin >> v1 >> v2;
	vector<long long> dist1(n+1,INF), dist2(n+1,INF), dist3(n+1,INF);
	dijkstra(1,dist1);
	dijkstra(v1,dist2);
	dijkstra(v2,dist3);
	long long ans = -1;
	long long r1 = dist1[v1];
	long long r2 = dist2[v2];
	long long r3 = dist3[n];
	if(!(r1==INF || r2 == INF || r3 == INF)){
		ans = r1+r2+r3;
	}
	long long r4 = dist1[v2];
	long long r5 = dist3[v1];
	long long r6 = dist2[n];
	if(!(r4==INF || r5==INF || r6==INF)){
		if(r4+r5+r6 < ans){
			ans = r4+r5+r6;
		}
	}
	cout << ans;
	return 0;
}