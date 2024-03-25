#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;

int main() {
	int px1,px2,px3;
	int py1,py2,py3;
	cin >> px1 >> py1;
	cin >> px2 >> py2;
	cin >> px3 >> py3;
	int vx1 = px2-px1;
	int vy1 = py2-py1;
	int vx2 = px2-px3;
	int vy2 = py2-py3;
	int mul = vx1*vy2 - vy1*vx2;
	int ans;
	if(mul==0){
		ans = 0;
	}
	else if(mul>0){
		ans = -1;
	}
	else{
		ans = 1;
	}
	cout << ans;
	return 0;
}