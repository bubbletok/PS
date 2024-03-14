#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool route[101][101] = {{false}};
vector<int> v[101];
bool visit[101] = {false};
void dfs(int start, int from, vector<int>& history){
	// 이전에 방문한 노드들 포함 route 업데이트
	for(int i=0; i<history.size(); i++){
		route[history[i]][start] = true;
	}
	visit[start] = true;
	for(int i=0; i<v[start].size(); i++){
		int next = v[start][i];
		// 다시 원래 출발 지점으로 돌아왔으면 route 업데이트
		if(next==from){
			route[from][next] = true;
		}
		if(visit[next]) continue;
		history.push_back(start);
		dfs(next,from,history);
		history.pop_back();
	}
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int a;
			cin >> a;
			if(a){
				v[i].push_back(j);
			}
		}
	}
	for(int i=0; i<n; i++){
		vector<int> hist;
		memset(visit,false,sizeof(visit));
		dfs(i,i,hist);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << route[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}