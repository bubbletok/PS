#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int ans = 0;
int arr[5][5];
bool colDone[6];
bool rowDone[6];
bool diaDone[2];
vector<pair<int, int>> v[26];

bool rowCheck(int col) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[col][i] == 0) cnt++;
    }
    return (cnt == 5);
}

bool colCheck(int row) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i][row] == 0) cnt++;
    }
    return (cnt == 5);
}

bool diaCheck(int type) {
    int cnt = 0;
    if (type == 0) {
        for (int i = 0; i < 5; i++) {
            if (arr[i][i] == 0) cnt++;
        }
    }
    else if (type == 1) {
        for (int i = 0; i < 5; i++) {
            if (arr[i][4 - i] == 0) cnt++;
        }
    }
    return (cnt == 5);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            v[arr[i][j]].push_back({ i,j });
        }
    }
    int ans = 0;
    int binggo = 0;
    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (found) break;
        for (int j = 0; j < 5; j++) {
            ans++;
            int a; cin >> a;
            int col = v[a][0].first;
            int row = v[a][0].second;
            //cout << col << " " << row << endl;
            arr[col][row] = 0;
            if (!colDone[row] && colCheck(row)) {
                //cout << "Col Bingo: " << a << " " << col << " " << row << endl;
                binggo++;
                colDone[row] = true;
            }
            if (!rowDone[col] && rowCheck(col)) {
                //cout << "Row Bingo: " << a << " " << col << " " << row << endl;
                binggo++;
                rowDone[col] = true;
            }
            if (col == row && !diaDone[0] && diaCheck(0)) {
                //cout << "Dia0 Bingo: " << a << " " << col << " " << row << endl;
                binggo++;
                diaDone[0] = true;
            }
            if (col + row == 4 && !diaDone[1] && diaCheck(1)) {
                //cout << "Dia1 Bingo: " << a << " " << col << " " << row << endl;
                binggo++;
                diaDone[1] = true;
            }
            //cout << "binggo: " << binggo << endl;
            if (binggo >= 3) {
                found = true;
                break;
            }
        }
    }
    cout << ans;

}