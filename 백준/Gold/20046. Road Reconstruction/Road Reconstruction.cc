#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define INF 999999
using namespace std;
using ll = long long;
using pr = pair<int, int>;

int n, m;
int arr[1001][1001];
bool check[1001][1001];
int cost[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = -1;
void bfs(int sx, int sy) {
    check[sy][sx] = true;
    priority_queue<pair<int, pr>, vector<pair<int,pr>>, greater<pair<int,pr>>> pq;
    int sc = arr[sy][sx];
    pq.push({ sc, {sx,sy} });
    cost[sy][sx] = sc;
    while (!pq.empty()) {
        int fx = pq.top().second.first;
        int fy = pq.top().second.second;
        int fc = pq.top().first;
        pq.pop();
        if (fc == -1) continue;
        if (cost[fy][fx] < fc) continue;
        for (int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n && !check[ny][nx] && arr[ny][nx] != -1) {
                int nc = fc + arr[ny][nx];
                if (nc < cost[ny][nx]) {
                    pq.push({ nc,{nx,ny} });
                    cost[ny][nx] = nc;
                    check[ny][nx] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cost[i][j] = INF;
        }
    }
    bfs(0, 0);
    ans = cost[n - 1][m - 1];
    if (ans == INF) ans = -1;
    cout << ans;
    return 0;
}