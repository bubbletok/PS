#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
int ans = 0;
map<double, double> cand;
int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        double dis = sqrt(x * x + y * y);
        double inc = y / x;
        if (cand[inc] < dis) {
            cand[inc] = dis;
        }
    }
    cout << cand.size();
    return 0;
}