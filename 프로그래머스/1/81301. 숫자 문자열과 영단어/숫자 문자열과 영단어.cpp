#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string ns[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<int> nums;
    for(int i=0; i<s.size(); i++){
        if('0'<=s[i]&&s[i]<='9') nums.push_back(s[i]-'0');
        else{
            string tmp1 = s.substr(i,3);
            string tmp2 = s.substr(i,4);
            string tmp3 = s.substr(i,5);
            for(int j=0; j<10; j++){
                int num = j;
                bool check = false;
                if(ns[j]==tmp1){
                    cout << "#1\n";
                    i+=2; check = true;
                }
                else if(ns[j]==tmp2){
                    cout << "#2\n";
                    i+=3; check = true;
                }
                else if(ns[j]==tmp3){
                    cout << "#3\n";
                    i+=4; check = true;
                }
                if(check){
                    nums.push_back(num);
                    break;
                }
            }
        }
    }
    for(int i=nums.size()-1, j=0; i>=0; i--, j++){
        answer += nums[j]*pow(10,i);
    }
    return answer;
}