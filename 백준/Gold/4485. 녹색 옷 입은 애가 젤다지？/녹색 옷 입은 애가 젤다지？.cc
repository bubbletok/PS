#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
int n;
int arr[126][126];
bool check[126][126];
int dist[126][126];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0, };

bool isValid(int x, int y) {
    return (0 <= x < n && 0 <= y && y < n);
}

void dijk(int x, int y) {
    check[y][x] = true;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ -arr[y][x],{x,y} });
    while (!pq.empty()) {
        int fc = -pq.top().first;
        int fx = pq.top().second.first;
        int fy = pq.top().second.second;
        pq.pop();
        if (dist[fy][fx] < fc) continue;
        for (int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy [i];
            if (!isValid(nx, ny)) continue;
            int nc = fc + arr[ny][nx];
            if (nc < dist[ny][nx]) {
                dist[ny][nx] = nc;
                pq.push({ -nc,{nx,ny} });
            }
        }
    }
}

int main()
{
    int t = 0;
    while (1) {
        t++;
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                //check[i][j] = false;
                dist[i][j] = INF;
            }
        }
        memset(check, false, sizeof(check));
        dijk(0,0);
        cout << "Problem " << t << ": ";
        cout << dist[n - 1][n - 1] << "\n";
    }
    return 0;
}