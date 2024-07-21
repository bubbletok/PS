#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long int h[100001];

long long int solve(int left, int right){
    if(left==right) return h[left];
    int mid = (left+right)/2;
    long long int ret = max(solve(left,mid),solve(mid+1,right));
    int lo = mid, hi = mid+1;
    long long int height = min(h[lo],h[hi]);
    ret = max(ret,height*2);
    while(left < lo || hi < right){
        if(hi < right && (lo==left || h[lo-1] < h[hi+1])){
            hi++;
            height = min(height,h[hi]);
        }
        else{
            lo--;
            height = min(height,h[lo]);
        }
        ret = max(ret,height*(hi-lo+1));
    }
    return ret;
}

int main(){
    while(1){
    	ios::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
        cin >> n;
        if(n==0)
        	break;
        for(int i=0; i<n; i++) cin >> h[i];
        long long int ans = solve(0,n-1);
        cout << ans << "\n";
    }
    return 0;
}