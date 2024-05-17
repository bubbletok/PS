#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int num = 0;
	while(!cin.eof()){
		string s;
		cin >> s;
		if(s[s.size()-1]!='\0') num++;
	}
	cout << num;
	return 0;
}