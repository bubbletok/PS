#include <iostream>
#include <cmath>
using namespace std;

int toInt(string& n){
	int tmp = 0;
	for(int i=0; i<n.size(); i++){
		tmp += pow(10,i) * (n[n.size()-1-i] - '0');
	}
	return tmp;
}

int main() {
	string n;
	int f;
	cin >> n >> f;
	n[n.size()-1] = '0';
	n[n.size()-2] = '0';
	while(toInt(n)%f!=0){
		if(n[n.size()-1] == '9')
		{
			n[n.size()-2]++;	
			n[n.size()-1] = '0';
		}
		else{
			n[n.size()-1]++;
		}
	}
	cout << n[n.size()-2] << n[n.size()-1];
	return 0;
}