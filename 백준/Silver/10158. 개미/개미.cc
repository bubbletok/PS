#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;

int main()
{
    int w, h; cin >> w >> h;
    int p, q; cin >> p >> q;
    int t; cin >> t;
    // x: 0~6
    // 4 -> 2 -> 0 -> 6 -> 0 ..
    // 1 -> 4 -> 0 -> 4 -> 0 ...
    // x는 0~w사이를 왔다갔다함
    // y는 0~h사이를 왔다갔다함
    // 즉, t초 후 x 좌표는 (p+t)%w, y 좌표는 (q+t)%h
    int x = (p + t) % w;
    int y = (q + t) % h;
    if ((p+t)/w%2!=0) {
        if (y == 0) x = w;
        else x = w - x;
    }
    if ((q + t) / h % 2 != 0) {
        if (y == 0) y = h;
        else y = h - y;
    }
    cout << x << " " << y << endl;
    //만약 w, h로 나눈 나머지가 0이 아닌 경우?
    // (4, 1)의 8초 후는 (4+8,1+8) = (12, 9) /w,/h-> (0,1)
    // (5, 3)의 4초 후는 (5+4,3+4) = (9,7) /w,/h -> (3,3)??
    // 만약 나눈 나머지가 0이 아닌 경우
    // 몫%2==0이면 그대로 두고 아니면 w, h에서 해당 좌표를 빼줌
    return 0;
}