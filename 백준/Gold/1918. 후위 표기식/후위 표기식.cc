#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
string str;
map<char, int> ord;
int main()
{
    cin >> str;
    vector<char> s;
    stack<char> oper;
    int len = str.size();
    ord['+'] = 0; ord['-'] = 0;
    ord['*'] = 1; ord['/'] = 1;
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if ('A' <= c && c <= 'Z') s.push_back(c);
        else {
            if (c == '(') {
                oper.push(c);
            }
            else if (c == ')') {
                while (!oper.empty() && oper.top() != '(') {
                    s.push_back(oper.top());
                    oper.pop();
                }
                oper.pop();
            }
            else{
                while (!oper.empty() && oper.top() != '(' && ord[oper.top()]>=ord[c]) {
                    s.push_back(oper.top());
                    oper.pop();
                }
                oper.push(c);
            }
        }
    }
    while (!oper.empty()) {
        s.push_back(oper.top());
        oper.pop();
    }
    for (auto i : s) cout << i;
    return 0;
}