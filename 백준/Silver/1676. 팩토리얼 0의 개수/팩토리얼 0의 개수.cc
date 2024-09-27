#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, count = 0;
	cin >> n;
	for(int i=1; pow(5,i) <= n; i++){
		count += n/pow(5,i);
	}
	cout << count;
	return 0;
}