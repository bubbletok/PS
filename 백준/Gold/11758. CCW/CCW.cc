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
	int ans;
	int vx1 = px2-px1;
	int vy1 = py2-py1;
	int vx2 = px3-px2;
	int vy2 = py3-py2;
	int vvx1 = -vy1;
	int vvy1 = vx1;
	
	double ddot = vvx1*vx2 + vvy1*vy2;
	double llen = sqrt(vvx1*vvx1 + vvy1*vvy1) * sqrt(vx2*vx2 + vy2*vy2);
	double _ccos = ddot/llen;
	if(_ccos==0){
		ans = 0;
	}
	else if(_ccos > 0){
		ans = 1;
	}
	else{
		ans = -1;
	}
	cout << ans;
	return 0;
}