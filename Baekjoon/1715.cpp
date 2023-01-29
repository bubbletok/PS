#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>> arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int sum = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        arr.push(a);
    }
    while(arr.size() != 1){
        int t1 = arr.top();
        arr.pop();
        int t2 = arr.top();
        arr.pop();
        sum += t1 + t2;
        arr.push(t1+t2);
    }
    cout << sum;
	return 0;
}