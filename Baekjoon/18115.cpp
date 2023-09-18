#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	deque<int> dq,ans;
	for(int i=0; i<n; i++){
		dq.push_back(i+1);
	}
	int skill[1000001];
	for(int i=0; i<n; i++){
		cin >> skill[i];
	}
	for(int i=n-1; i>=0; i--){
		if(skill[i]==1){
			ans.push_front(dq.front());
			dq.pop_front();
		}
		else if(skill[i]==2){
			int dqF = dq.front();
			dq.pop_front();
			int ansF = ans.front();
			ans.pop_front();
			ans.push_front(dqF);
			ans.push_front(ansF);
		}
		else{
			ans.push_back(dq.front());
			dq.pop_front();
		}
	}
	for(int i : ans){
		cout << i << " ";
	}
	return 0;
}