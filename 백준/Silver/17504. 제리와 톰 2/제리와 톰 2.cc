#include <iostream>
#include <string.h>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
string s;
ll n;
ll arr[16];

pair<ll,ll> f(ll A, pair<ll,ll> B) {
    return { B.second, A* B.second + B.first };
}

pair<ll,ll> cal(int cnt) {
    if (cnt == n-2) {
        return f(arr[cnt], { 1,arr[cnt+1] });
    }
    return f(arr[cnt], cal(cnt + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    pair<ll, ll> ans = cal(0);
    cout << ans.second - ans.first << " " << ans.second;

}