#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <set>
using namespace std;
int n;
int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int ans = 0;
    int s = 0, e = 0;
    multiset<int> ms;
    ms.insert(arr[0]);
    int _min = arr[0], _max = arr[0];
    while(e<n&&s<n){
        if(abs(_max-_min)<=2){
            ans = max(ans,e-s+1);
            e++;
            ms.insert(arr[e]);
        }
        else{
            auto it = ms.find(arr[s]);
            ms.erase(it);
            s++;
        }
        auto begin_it = ms.begin();
        auto end_it = ms.end(); end_it--;
        _min = *begin_it;
        _max = *end_it;
    }
    cout << ans;
    return 0;
}