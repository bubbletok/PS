#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long int dp[92][2];
    cin >> n;
    n = 90;
    dp[1][0] = 0, dp[1][1] = 1;
    dp[2][0] = 1, dp[2][1] = 0;
    dp[3][0] = 1, dp[3][1] = 1;
    for(int i=4; i<=n; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    for(int i=1; i<=n; i++){
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << dp[n][0] + dp[n][1];
    return 0;
}