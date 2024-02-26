#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	stack<int> s;
	bool check = true;
	for(int i=str.size()-1; i>=0; i--){
		if(str[i]=='x'){
			s.push(0);
		}
		else if(str[i]=='g'){
            if(s.size()<1){
                check = false;
                break;
            }
			int tmp = s.top()+1;
			s.pop();
			s.push(tmp);
		}
		else if(str[i]=='f'){
			if(s.size()<2){
				check = false;
				break;
			}
			int S, T;
			S = s.top(), s.pop();
			T = s.top(), s.pop();
			s.push(min(S,T));
		}
	}
	if(!check || s.size()!=1){
		cout << -1;
	}
	else
		cout << s.top();
	return 0;
}