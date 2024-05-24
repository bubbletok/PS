#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> lotto;
bool check[50];
int k;
void dfs(int start, int cnt, vector<int>& v){
	if(cnt == 6){
		for(int i=0; i<lotto.size(); i++){
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=0; i<v.size(); i++){
		int next = v[i];
		if(check[next]) continue;
		if(!lotto.empty() && lotto.back() >= next) continue;
		lotto.push_back(next);
		check[next] = true;
		dfs(next,cnt+1,v);
		lotto.pop_back();
		check[next] = false;
	}
}

int main() {
	while(1){
		cin >> k;
		if(k==0) break;
		vector<int> v;
		for(int i=0; i<k; i++){
			int a;
			cin >> a;
			v.push_back(a);
		}
		dfs(v[0],0,v);
		cout << "\n";
	}
	return 0;
}