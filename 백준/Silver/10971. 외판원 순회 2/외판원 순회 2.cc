#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,int>> v[11];
int n;
long long int ans = 1000000000;
void dfs(int start, int cnt, int sum, int from, bool check[11])
{
/*	cout << "start: " << start << endl;
	cout << "sum: " << sum << endl;*/

	if(start==from && cnt == n)
	{
		ans = sum < ans ? sum : ans;
	}
	for(int i=0; i<v[start].size(); i++){
		int next = v[start][i].first;
		if(!check[next])
		{
			//cout << "start: " << start << ", next: " << next << endl;
			check[next] = true;
			sum += v[start][i].second;
			cnt++;
			dfs(next,cnt,sum,from,check);
			check[next] = false;
			sum -= v[start][i].second;
			cnt--;
		}
	}
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int a;
			cin >> a;
			if(a==0) continue;
			v[i].push_back({j,a});
		}
	}
/*	for(int i=0; i<n; i++){
		cout << "i: " << i << endl;
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j].first << " " << v[i][j].second << " ";
		}
		cout << endl;
	}*/
	for(int i=0; i<n; i++){
		//cout << "i: " << i << endl;
		bool check[11] = {false};
		dfs(i,0,0,i,check);
	}

	cout << ans;
	return 0;
}