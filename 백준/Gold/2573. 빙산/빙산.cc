#include <iostream>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
using ll = long long;
int n, m;
int arr[301][301];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool check[301][301];
int cnts[301][301];
queue<pair<int, int>> bing;
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    check[y][x] = true;
    while (!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n && !check[ny][nx] && arr[ny][nx]!=0) {
                q.push({ nx,ny });
                check[ny][nx] = true;
            }
        }
    }
}

void deform() {
    queue<pair<int, int>> zeros;
    int len = bing.size();
    for (int i = 0; i < len; i++) {
        int fx = bing.front().first;
        int fy = bing.front().second;
        bing.pop();
        arr[fy][fx] -= cnts[fy][fx];
        if (arr[fy][fx] <= 0) {
            arr[fy][fx] = 0;
            zeros.push({ fx,fy });
        }
        else {
            bing.push({ fx,fy });
        }
    }
    while (!zeros.empty()) {
        int fx = zeros.front().first;
        int fy = zeros.front().second;
        zeros.pop();
        for (int k = 0; k < 4; k++) {
            int nx = fx + dx[k];
            int ny = fy + dy[k];
            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                if (arr[ny][nx] != 0) {
                    cnts[ny][nx]++;
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
            if (arr[i][j] != 0) {
                bing.push({j,i});
            }
        }
    }
    memset(cnts, 0, sizeof(cnts));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                        if (arr[ny][nx] != 0) {
                            cnts[ny][nx]++;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    bool deformed = false;
    while (1) {
        ans++;
        deform();
        memset(check, false, sizeof(check));
        int cnt = 0;
        int len = bing.size();
        for (int i = 0; i < len; i++) {
            int fx = bing.front().first;
            int fy = bing.front().second;
            bing.pop();
            bing.push({ fx,fy });
            if (check[fy][fx]) continue;
            bfs(fx, fy);
            cnt++;
            if (cnt >= 2) {
                deformed = true;
                break;
            }
        }
        if (cnt == 0) {
            break;
        }
        if (cnt >= 2) {
            deformed = true;
            break;
        }
    }
    if (!deformed) ans = 0;
    cout << ans;
    return 0;
}