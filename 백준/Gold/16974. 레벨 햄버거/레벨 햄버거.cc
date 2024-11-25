#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
ll ans = 0;
ll bugger[51];
ll pat[51];
ll eat(ll level, ll x) {
    //cout << "level: " << level << ", x: " << x << endl;
    if (x == 0) return 0;
    if (level == 0) return 1;
    if (x == bugger[level] || x == bugger[level] - 1) {
        return pat[level-1] * 2 + 1;
    }

    ll preBugger = bugger[level - 1];
    ll total = 0;
    x--; // bun

    ll amount = min(x, preBugger); x -= preBugger;
    total += eat(level - 1, amount);
    if (x <= 0) return total;

    total += 1; x--; // 1 patty

    amount = min(x, preBugger); x -= preBugger;
    total += eat(level - 1, amount);

    x--; // bun
    return total;
}
int main()
{
    ll n, x; cin >> n >> x;
    bugger[0] = 1;
    pat[0] = 1;
    for (int i = 1; i <= 50; i++) {
        bugger[i] = 3 + bugger[i - 1] * 2;
        pat[i] = 1 + pat[i - 1] * 2;
    }
    //cout << bugger[50] << endl;
    ll ans = eat(n, x);
    cout << ans;
    return 0;
}