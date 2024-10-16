#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
using ll = long long;
using pr = pair<int, int>;
int inf = 9999999;
int dp[100001][5][5];
int cost[5][5];
vector<int> list;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1) {
        int next; cin >> next;
        if (next == 0) break;
        list.push_back(next);
    }
    n = list.size();

    for (int i = 1; i <= 4; i++) {
        cost[0][i] = 2;
        cost[i][i] = 1;
    }
    cost[1][2] = 3; cost[1][3] = 4; cost[1][4] = 3;
    cost[2][1] = 3; cost[2][3] = 3; cost[2][4] = 4;
    cost[3][1] = 4; cost[3][2] = 3; cost[3][4] = 3;
    cost[4][1] = 3; cost[4][2] = 4; cost[4][3] = 3;

    memset(dp, inf, sizeof(dp));
    dp[0][0][0] = 0;
    int ans = inf;
    for (int i = 0; i < n; i++) {
        int next = list[i];
        for (int l = 0; l < 5; l++) {
            for (int r = 0; r < 5; r++) {
                dp[i+1][l][next] = min(dp[i+1][l][next], dp[i][l][r] + cost[r][next]);
                dp[i+1][next][r] = min(dp[i+1][next][r], dp[i][l][r] + cost[l][next]);
            }
        }
    }
    for (int l = 0; l < 5; l++) {
        for (int r = 0; r < 5; r++) {
            ans = min(ans, dp[n][l][r]);
        }
    }
    cout << ans;
    return 0;
}