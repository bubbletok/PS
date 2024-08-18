#include <iostream>
#include <string.h>
#include <string>
using namespace std;
using ll = long long;
int n, m, ox, oy, k;
int arr[22][22];
int dice[4][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

void rollDice(int x, int y) {
    if (arr[y][x] == 0) {
        arr[y][x] = dice[3][1];
    }
    else {
        dice[3][1] = arr[y][x];
        arr[y][x] = 0;
    }
}

void left(int& x, int& y) {
    if (x == 0) return;
    x--;
    int tmp = dice[3][1];
    dice[3][1] = dice[1][0];
    dice[1][0] = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = tmp;
    rollDice(x, y);
    cout << dice[1][1] << "\n";
}

void right(int& x, int& y) {
    if (x == m - 1) return;
    x++;
    int tmp = dice[1][2];
    dice[1][2] = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = dice[3][1];
    dice[3][1] = tmp;
    rollDice(x, y);
    cout << dice[1][1] << "\n";
}

void up(int& x, int& y) {
    if (y == 0) return;
    y--;
    int tmp = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = tmp;
    rollDice(x, y);
    cout << dice[1][1] << "\n";
}

void down(int& x, int& y) {
    if (y == n - 1) return;
    y++;
    int tmp = dice[3][1];
    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = dice[0][1];
    dice[0][1] = tmp;
    rollDice(x, y);
    cout << dice[1][1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> oy >> ox >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int dir; cin >> dir;
        if (dir == 1) right(ox, oy);
        else if (dir == 2) left(ox, oy);
        else if (dir == 3) up(ox, oy);
        else down(ox, oy);
    }
    return 0;
}