#include <iostream>
#include <stack>
using namespace std;
using ll = long long;
string str;

int main()
{
    cin >> str;
    stack<ll> s;
    ll ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (s.empty()) s.push(str[i]);
        else {
            if (str[i]==')' && s.top()!='[' && s.top()!=']' && s.top()!=')') {
                ll tmp = 0;
                while (!s.empty() && s.top() != '[' && s.top() != ']' && s.top() != '(' && s.top()!=')') {
                    tmp += (int)s.top();
                    s.pop();
                }
                if (!s.empty()) {
                    if (s.top() == '(') {
                        s.pop();
                    }
                    else {
                        s.push(str[i]);
                        continue;
                    }
                }
                if (tmp == 0) tmp = 1;
                tmp *= 2;
                if (s.empty()) {
                    ans += tmp;
                }
                else {
                    s.push(tmp);
                }
            }
            else if (str[i]==']' && s.top() != '(' && s.top() != ')' && s.top() != ']') {
                ll tmp = 0;
                while (!s.empty() && s.top() != '(' && s.top() != ')' && s.top() != '[' && s.top() != ']') {
                    tmp += (int)s.top();
                    s.pop();
                }
                if (!s.empty()) {
                    if (s.top() == '[') {
                        s.pop();
                    }
                    else {
                        s.push(str[i]);
                        continue;
                    }
                }

                if (tmp == 0) tmp = 1;
                tmp *= 3;
                if (s.empty()) {
                    ans += tmp;
                }
                else {
                    s.push(tmp);
                }
            }
            else {
                s.push(str[i]);
            }
        }
    }
    if (!s.empty()) ans = 0;
    cout << ans;
    return 0;
}