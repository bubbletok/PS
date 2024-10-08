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
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int answer = 0;
        for (int j = 1; j <= 10; j++) {
            int a; cin >> a;
            if ((j - 1) % 5 + 1 == a) {
                answer++;
            }
        }
        if (answer==10) cout << i << "\n";
    }
    return 0;
}