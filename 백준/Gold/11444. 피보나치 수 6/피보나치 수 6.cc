#include <iostream>
using namespace std;
using ll = long long;
ll n;
ll m = 1000000007;
struct matrix {
    int size = 2;
    ll element[2][2] = { {0,0},{0,0} };

    matrix& operator*(const matrix& b) {
        matrix newMatrix = matrix();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    newMatrix.element[i][k] += (this->element[i][j] * b.element[j][k] % m)%m;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                this->element[i][j] = newMatrix.element[i][j]%m;
            }
        }
        return *this;
    }
};

matrix pow(matrix a, ll k) {
    if (k == 1) return a;
    matrix tmp = pow(a, k / 2);
    if (k % 2 == 0) return tmp * tmp;
    return tmp * tmp * a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    matrix a = matrix();
    a.element[0][0] = 1;
    a.element[0][1] = 1;
    a.element[1][0] = 1;
    a.element[1][1] = 0;;
    a = pow(a, n);
    cout << a.element[1][0];
    return 0;
}