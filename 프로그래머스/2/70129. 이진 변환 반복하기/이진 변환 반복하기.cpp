#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int operCnt = 0;
    int cnt = 0;
    while(1){
        if(s=="1") break;
        string tmp = "";
        for(auto i : s) if(i=='1') tmp = tmp + i;
        int dif = s.size()-tmp.size();
        cnt += dif;
        operCnt++;
        
        int c = tmp.size();
        bool start = false;
        string newS = "";
        for(int i=20; i>=0; i--){
            int di = pow(2,i);
            int val = c/di;
            if(start){
                newS += '0' + val;
            }
            else if(val!=0&&!start){
                start = true;
                newS += '0' + val;
            }
            c %= di;
        }
        s = newS;
    }
    answer.push_back(operCnt);
    answer.push_back(cnt);
    return answer;
}