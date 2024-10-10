#include <iostream>
using namespace std;
using ll = long long;
int n, m, k;
char arr[2001][2001];
int dp[2][2001][2001] = { 0 };
// dp[0]: 맨 처음이 B일 때 고쳐야 되는 개수
// dp[1]: 맨 처음이 W일 때 고쳐야 되는 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int idx = (i + j) % 2;
            int ba = (arr[i][j] == 'B');
            int wa = (arr[i][j] == 'W');
            dp[0][i+1][j+1] = dp[0][i+1][j] + dp[0][i][j+1] - dp[0][i][j] + (idx == 0 ? wa : ba);
            dp[1][i+1][j+1] = dp[1][i+1][j] + dp[1][i][j+1] - dp[1][i][j] + (idx == 0 ? ba : wa);
        }
    }

    int ans = 2000*2000+2000;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {           
            int fb = dp[0][i + k][j + k] - dp[0][i][j + k] - dp[0][i + k][j] + dp[0][i][j];
            int fw = dp[1][i + k][j + k] - dp[1][i][j + k] - dp[1][i + k][j] + dp[1][i][j];
            int tmp = min(fb, fw);
            ans = min(ans, tmp);
        }
    }
    cout << ans;
    return 0;
}