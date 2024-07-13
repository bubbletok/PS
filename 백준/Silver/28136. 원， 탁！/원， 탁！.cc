#include <iostream>
#include <deque>
using namespace std;
int main() {
    int n;
    cin >> n;
    deque<int> dq;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        dq.push_back(a);
    }
    int ans = 0;
    for(int i=0; i<n-1; i++){
        if(dq[i]>=dq[i+1]){
            ans++;
        }
    }
    if(dq[n-1]>=dq[0]) ans++;
    cout << ans;
    return 0;
}