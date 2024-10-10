#include <iostream>
#include <string.h>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;
ll n;
int dp[501][501]; // dp[i][j] = A_i ~ A_j 까지의 행렬 곱의 최소 연산 횟수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<int,int>> m;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        m.push_back({ r,c });
    }
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int dia = 1; dia <= n - 1; dia++) {
        for (int i = 1; i <= n - dia; i++) {
            int j = i + dia;
            dp[i][j] = dp[i][i] + dp[i + 1][j] + m[i - 1].first * m[i].first * m[j-1].second;
            for (int k = i+1; k < j; k++) {
                int tmp = dp[i][k] + dp[k + 1][j] + m[i - 1].first * m[k].first * m[j - 1].second;
                if (tmp < dp[i][j]) {
                    dp[i][j] = tmp;
                }
            }
        }
    }
    cout << dp[1][n];
    return 0;
}