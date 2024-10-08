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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, i, a, r, c;
    cin >> h >> i >> a >> r >> c;
    cout << h * i - a * r * c;
    return 0;
}