#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned long long int s, n=0, sum = 0;
	cin >> s;

	for(int i=1; i<=(-1+sqrt(1+(8*s)))/2; i++){
		sum += i;
		n++;
		if (sum>s){
			sum -= i;
			n--;
			break;	
		}
	}
	cout << n;
	return 0;
}