#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    deque<pair<int,int>> dq(n);
    for(int i=0; i<n; i++){
    	int a;
    	cin >> a;
    	dq[i] = {a,i+1};
    }
    int idx = 0;
    while(!dq.empty()){
    	int x = dq.front().first;
    	cout << dq.front().second << " ";
    	dq.pop_front();
    	if(x>0){
    		for(int i=0; i<x-1; i++){
    			dq.push_back(dq.front());
    			dq.pop_front();
    		}
    	}
    	else{
    		for(int i=0; i<(-1)*x; i++){
    			dq.push_front(dq.back());
    			dq.pop_back();
    		}
    	}
    }
    return 0;
}