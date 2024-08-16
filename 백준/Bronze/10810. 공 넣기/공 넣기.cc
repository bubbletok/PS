#include <iostream>
using namespace std;

int main() {
    int n,m;
    int num[102] = {0};
    cin >> n >> m;
    for(int a=0; a<m; a++){
        int i,j,k;
        cin >> i >> j >> k;
        for(int s = i; s <= j; s++){
            num[s-1] = k;
        }
    }
    for(int i=0; i<n; i++){
        cout << num[i] << " ";
    }
    return 0;
}