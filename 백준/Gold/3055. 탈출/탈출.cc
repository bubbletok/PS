#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;
int r, c;
char arr[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<pair<int, int>> water;
bool check[51][51];
int dist[51][51];
bool waterCheck[51][51];
bool isValid(int x, int y) {
    return (0 <= x && x < c && 0 <= y && y < r);
}

void bfs(int x, int y) {
    queue<pair<int, int>> gq;
    queue<pair<int, int>> wq;
    check[y][x] = true;
    dist[y][x] = 0;
    gq.push({ x,y });
    for (auto i : water) {
        check[i.second][i.first] = true;
        waterCheck[i.second][i.first] = true;
        wq.push({ i.first,i.second });
    }
    while (!gq.empty() || !wq.empty()) {
        // water first
        queue<pair<int, int>> tmp;
        while (!wq.empty()) {
            int wfx = wq.front().first;
            int wfy = wq.front().second;
            wq.pop();
            //cout << "front: " << wfx << " " << wfy << endl;
            for (int i = 0; i < 4; i++) {
                int wnx = wfx + dx[i];
                int wny = wfy + dy[i];
                //cout << wnx << " " << wny << endl;
                //cout << waterCheck[wny][wnx] << endl;
                if (isValid(wnx, wny) && !waterCheck[wny][wnx] && arr[wny][wnx] != 'D' && arr[wny][wnx]!='X') {
                    tmp.push({ wnx,wny });
                    check[wny][wnx] = true;
                    waterCheck[wny][wnx] = true;
                }
            }
        }
        while (!tmp.empty()) {
            wq.push({ tmp.front().first, tmp.front().second });
            tmp.pop();
        }

        //for (int i = 0; i < c; i++) {
        //    for (int j = 0; j < r; j++) {
        //        cout << check[i][j] << " ";
        //    }
        //    cout << endl;
        //}
        //cout << endl;
        
        //gosum after
        queue<pair<int, int>> tmp2;
        while (!gq.empty()) {
            int gfx = gq.front().first;
            int gfy = gq.front().second;
            gq.pop();
            for (int i = 0; i < 4; i++) {
                int gnx = gfx + dx[i];
                int gny = gfy + dy[i];
                if (isValid(gnx, gny) && !check[gny][gnx] && arr[gny][gnx] != 'X') {
                    tmp2.push({ gnx,gny });
                    check[gny][gnx] = true;
                    dist[gny][gnx] = dist[gfy][gfx] + 1;
                }
            }
        }
        while (!tmp2.empty()) {
            gq.push({ tmp2.front().first, tmp2.front().second });
            tmp2.pop();
        }
    }
}

int main()
{
    cin >> r >> c;
    int sx = 0, sy = 0;
    int ex = 0, ey = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                sx = j; sy = i;
            }
            else if (arr[i][j] == '*') {
                water.push_back({ j,i });
            }
            else if (arr[i][j] == 'D') {
                ex = j; ey = i;
            }
            check[i][j] = false;
        }
    }
    bfs(sx, sy);

    if (dist[ey][ex] == 0) cout << "KAKTUS";
    else cout << dist[ey][ex];
    return 0;
}