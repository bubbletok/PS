#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int n;
ll m = 1000000000;
int dp[101][10][1024];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	cin >> n;
	// 기존
	//dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
	// 비트마스크를 쓰는 이유
	// -> 현재(n)까지 방문한(처리한) 경우를 저장해서 사용하기 위함.'

	for (int k = 1; k <= 9; k++) {
		dp[1][k][1 << k] = 1; // 1~9까지의 숫자는 방문한 숫자가 각각 자기 자신임(1<<k)
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int bit = 0; bit < 1 << 10; bit++) {
				// bit | (1 << j) -> 이전까지 방문한 기록에 현재 숫자 j 방문했다고 기록함
				//dp[i][j][] = dp[]
				int newBit = bit | (1 << j);
				if (j < 9) dp[i][j][newBit] += dp[i - 1][j + 1][bit];
				if (j > 0) dp[i][j][newBit] += dp[i - 1][j - 1][bit];
				dp[i][j][newBit] %= m;
			}
		}
	}
	//dp[n][m][1<<k]: 길이가 n인 숫자에서 끝자리가 m이고 현재까지 방문한 숫자 집합이 1<<k인 경우의 수
	ll sum = 0;
	for (int j = 0; j <= 9; j++) {
		sum += dp[n][j][1023];
		sum %= m;
	}
	cout << sum;
}