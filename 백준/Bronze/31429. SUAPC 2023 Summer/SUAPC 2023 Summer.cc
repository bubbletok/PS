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
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int arr[12] = { 0,1600,894,1327,1311,1004,1178,1357,837,1055,556,773 };
    int cnt[12] = { 0, 12, 11, 11,10,9,9,9,8,7,6,6 };
    cout << cnt[n] << " " << arr[n];
    return 0;
}