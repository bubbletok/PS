#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
using pr = pair<ll, ll>;
int n, m;
ll mem[101];
ll cost[101];
ll dp[101][10001] = { 0 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ll curMem = 0;
    for (int i = 1; i <= n; i++) {
        cin >> mem[i];
    }
    int totalCost = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        totalCost += cost[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int c = 0; c <= totalCost; c++) {
            if (cost[i] > c) {
                dp[i][c] = dp[i - 1][c];
            }
            else {
                dp[i][c] = max(mem[i] + dp[i - 1][c - cost[i]], dp[i - 1][c]);
            }
        }
    }
    for (int c = 0; c <= totalCost; c++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][c] >= m) {
                cout << c;
                return 0;
            }
        }
    }
    ///dp[i][M] = i번째까지 탐색했을 때 메모리 M을 확보하기 위한 최소 비용
    //M이 최대 천만이므로 배열을 만들 수 없음

    // dp[i][c] = i번째까지 탐색했을 때 비용이 c가 되는 최대 메모리
    return 0;
}