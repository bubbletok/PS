#include <iostream>
#include <vector>
#include <queue>
#define INF 9999999
using namespace std;
int V,E,K;
vector<pair<int,int>> graph[20001];
vector<int> dist(20000+1,INF);

void dijkstra(int start){
	priority_queue<pair<int,int>> q;
	dist[start] = 0;
	q.push({0, start});
	while(!q.empty()){
		int node = q.top().second;
		int curDist = -q.top().first;
		q.pop();
		if(dist[node] < curDist) continue;
		for(int i=0; i<graph[node].size(); i++){
			int newNode = graph[node][i].first;
			int newDist = curDist + graph[node][i].second;
			if(newDist < dist[newNode]){
				dist[newNode] = newDist;
				q.push({-newDist,newNode});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	cin >> K;
	for(int i=0; i<E; i++){
		int u,v,w;
		cin >> u >> v >> w;
		graph[u].push_back({v,w});
	}
	dijkstra(K);
	for(int i=1; i<=V; i++){
		if(dist[i]==INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}