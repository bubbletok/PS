// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int a,b;
int deci[4] = {1,10,100,1000};
bool check[100000];

int d(int x){
    x*=2;
    if(x>9999) return x%10000;
    return x;
}
int s(int x){
    return (x==0) ? 9999 : x-1;
}
int l(int x){
    int n = x/1000;
    x%=1000; x*=10; x+=n;
    return x;
}
int r(int x){
    int n = x%10;
    x/=10; x+=n*1000;
    return x;
}
vector<string> ans;
void bfs(int x){
    check[x] = true;
    queue<pair<int,string>> q;
    q.push({x,""});
    while(!q.empty()){
        int f = q.front().first;
        string str = q.front().second;
        q.pop();
        if(f==b){
            ans.push_back(str);
            return;
        }
        int dd = d(f);
        int ss = s(f);
        int ll = l(f);
        int rr = r(f);
        if(!check[dd]){
            check[dd]=true;
            q.push({dd,str+'D'});
        }
        if(!check[ss]){
            check[ss] = true;
            q.push({ss,str+'S'});
        }
        if(!check[ll]){
            check[ll] = true;
            q.push({ll,str+'L'});
        }
        if(!check[rr]){
            check[rr] = true;
            q.push({rr,str+'R'});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    memset(check,false,sizeof(check));
		cin >> a >> b;
	    bfs(a);
	}
	for(int i=0; i<ans.size(); i++){
	    cout << ans[i] << "\n";
	}
	return 0;
}