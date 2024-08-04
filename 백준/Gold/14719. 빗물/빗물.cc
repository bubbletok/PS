#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int h, w;
int height[501];
int ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    cin >> h >> w;
    for (int i = 1; i <= w; i++) {
        cin >> height[i];
    }
    for (int i = 1; i <= h; i++) {
        int tmp = 0;
        bool open = false;
        for (int j = 1; j <= w; j++) {
            if (height[j] >= i && !open) {
                open = true;
                continue;
            }
            if (height[j] < i) {
                if (open) {
                    tmp++;
                }
            }
            else{
                if (open && tmp != 0) {
                    //cout << i << " " << j << endl;
                    //cout << tmp << endl;
                    ans += tmp;
                    tmp = 0;
                }
            }
            //cout << j << " " << "open: " << open << endl;
        }
    }
    std::cout << ans;
}