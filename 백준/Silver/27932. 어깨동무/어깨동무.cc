#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, k;
int arr[1000001];
vector<int> v;
int param(int s, int e){
    while(s<e){
        bool check[1000001];
        memset(check,false,sizeof(check));
        int m = (s+e)/2;
        int cnt = 0;
        for(int i=0; i<n; i++){
            int left=i-1, right=i+1;
            if(left<0) left=0;
            if(right>=n) right=n-1;
            if(abs(arr[left]-arr[i])>m){
                if(!check[left]){
                    check[left] = true;
                    cnt++;
                }
            }
            if(abs(arr[right]-arr[i])>m){
                if(!check[right]){
                    check[right] = true;
                    cnt++;
                }
            }
        }
        if(cnt<=k){
            e = m;
        }
        else{
            s = m+1;
        }
    }
    return e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(n==1) v.push_back(arr[i]);
        else if(i!=0){
            v.push_back(abs(arr[i]-arr[i-1]));
        }
    }
    sort(v.begin(),v.end());
    int ans = param(0,1000000000+1);
    cout << ans;
    return 0;
}