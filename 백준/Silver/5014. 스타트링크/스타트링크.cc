#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check[1000001];
int f,s,g,u,d;
int ans = -1;
void bfs(int start){
	queue<pair<int,int>> q; // {floor, cnt}
	check[start] = true;
	q.push({start,0});
	while(!q.empty()){
		int flo = q.front().first;
		int cnt = q.front().second;
		if(flo==g){
			if(ans==-1) ans = cnt;
			else ans = ans > cnt ? cnt : ans;
		}
		q.pop();
		int up = flo + u;
		int down = flo - d;
		if(up<=f && !check[up]){
			q.push({up,cnt+1});
			check[up] = true;
		}
		if(down>=1 && !check[down]){
			q.push({down,cnt+1});
			check[down] = true;
		}
	}
}
int main() {
	cin >> f >> s >> g >> u >> d;
	bfs(s);
	if(ans==-1){
		cout << "use the stairs";
	}
	else{
		cout << ans;
	}
	return 0;
}