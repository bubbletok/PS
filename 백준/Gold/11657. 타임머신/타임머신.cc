#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
vector<pair<int,pair<int,int>>> graph;
vector<long long> dist(500+1, INF);
int n,m;
bool ford(int start){
	dist[start] = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			int from = graph[j].first;
			int to = graph[j].second.first;
			long long cost = graph[j].second.second;
			
			if(dist[from]==INF) continue;
			
			long long new_cost = cost + dist[from];
			if(new_cost < dist[to]){
				dist[to] = new_cost;
				
				if(i==n) return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a,b;
		long long t;
		cin >> a >> b >> t;
		graph.push_back({a,{b,t}});
	}
	bool negative_cycle = ford(1);
	if(negative_cycle){
		cout << "-1\n";
	}
	else{
		for(int i=2; i<=n; i++){
			if(dist[i]==INF) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}
	return 0;
}