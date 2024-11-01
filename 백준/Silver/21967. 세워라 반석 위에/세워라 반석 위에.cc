#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <set>
using namespace std;
int n;
int arr[1000001];
int height[11];
int _max;
int _min;
void GetMaxMin(){
    int temp_max = 0;
    for(int i=1; i<=10; i++){
        if(height[i]>0){
            temp_max = i;
        }
    }
    int temp_min = 11;
    for(int i=10; i>=1; i--){
        if(height[i]>0){
            temp_min = i;
        }
    }
    _max = temp_max;
    _min = temp_min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    int s = 0, e = 0;
    _max = arr[0];
    _min = arr[0];
    height[arr[0]]++;
    while(e<n&&s<n){
        if(abs(_max-_min)<=2){
            e++;
            height[arr[e]]++;
        }
        else{
            height[arr[s]]--;
            s++;
        }
        GetMaxMin();
        ans = max(ans, (e-s));
    }
    cout << ans;
    return 0;
}