#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
using ll = long long;
int n, k;
deque<pair<int, bool>> dq;
int zeroCnt = 0;
int level = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n * 2; i++) {
        int a; cin >> a;
        dq.push_back({ a, false });
    }
    while (1) {
        dq.push_front(dq.back());
        dq.pop_back();

        if (dq[n - 1].second) {
            dq[n - 1].second = false;
        }

        for (int i = n-1; i >=0; i--) {
            if (dq[i].second && !dq[i + 1].second && dq[i + 1].first > 0) {
                dq[i].second = false;
                dq[i + 1].second = true;
                dq[i + 1].first--;
                if (dq[i + 1].first == 0) zeroCnt++;
                i++;
            }
        }

        if (dq[n - 1].second) {
            dq[n - 1].second = false;
        }

        if (dq[0].first > 0) {
            dq[0].first--;
            dq[0].second = true;
            if (dq[0].first == 0) zeroCnt++;
        }

        if (zeroCnt >= k) break;
        level++;
    }
    std::cout << level;
}