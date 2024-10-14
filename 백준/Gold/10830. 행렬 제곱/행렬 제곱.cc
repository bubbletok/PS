#include <iostream>
using namespace std;
using ll = long long;
int n;
ll b;
ll arr[6][6];
ll m = 1000;
struct matrix {
    int size;
    ll element[6][6];

    matrix(int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                element[i][j] = 0;
            }
        }
    }

    matrix& operator*(const matrix& b) {
        matrix newMatrix = matrix(n);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    newMatrix.element[i][j] += (this->element[i][k] * b.element[k][j] % m)%m;
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

    void print() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << element[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

matrix pow(matrix a, ll k) {
    if (k == 1) {
        return a;
    }
    if (k == 2) {
        return a * a;
    }
    matrix tmp = pow(a, k / 2);
    if (k % 2 == 0) {
        return tmp * tmp;
    }
    return tmp * tmp * a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> b;
    matrix a = matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a.element[i][j];
            a.element[i][j] %= m;
        }
    }
    a = pow(a, b);
    a.print();
    return 0;
}