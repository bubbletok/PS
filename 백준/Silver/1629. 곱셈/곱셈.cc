#include <iostream>
using namespace std;
long long int a,b,c;

long long int f(long long int count){
	if(count==1)
		return a%c;
    long long int tmp = f(count/2); 
	if(count%2 == 0)
		return ((tmp%c)*tmp%c)%c;
	else
		return ((tmp%c)*f(count/2+1)%c)%c;
}
int main() {
	cin >> a >> b >> c;
	cout << f(b);
	return 0;
}