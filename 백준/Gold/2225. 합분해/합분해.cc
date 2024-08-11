#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
int n, k;
ll dp[201][201];
ll divisor = 1000000000;

void cal(int a, int b) {
    for (int i = a; i >= 0; i--) {
        dp[a][b] += dp[i][b-1] % divisor;
        dp[a][b] %= divisor;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }
    for (int i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j<=k; j++) {
            cal(i, j);
        }
    }
    /*for (int i = 0; i <= n; i++) {
        cout << "num: " << i << ", ";
        for (int j = 1; j <= k; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }*/
    cout << dp[n][k] % divisor;
    return 0;
}