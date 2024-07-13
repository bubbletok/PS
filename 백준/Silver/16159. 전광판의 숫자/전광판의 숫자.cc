// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s[7];
vector<int> v;
vector<int> next_num;
string ans[7];

string nums[10][7] = {
    {//0
        "000000",
        "001100",
        "010010",
        "010010",
        "010010",
        "001100",
        "000000"
    },
    {//1
        "000000",
        "000100",
        "001100",
        "000100",
        "000100",
        "000100",
        "000000"
    },
    {//2
        "000000",
        "011110",
        "000010",
        "011110",
        "010000",
        "011110",
        "000000"
    },
    {//3
        "000000",
        "011100",
        "000010",
        "000100",
        "000010",
        "011100",
        "000000"
    },
    {//4
        "000000",
        "000100",
        "001100",
        "010100",
        "111110",
        "000100",
        "000000"
    },
    {//5
        "000000",
        "011110",
        "010000",
        "011100",
        "000010",
        "010010",
        "001100"
    },
    {//6
        "000000",
        "010000",
        "010000",
        "011110",
        "010010",
        "011110",
        "000000"
    },
    {//7
        "000000",
        "011110",
        "000010",
        "000100",
        "000100",
        "000100",
        "000000"
    },
    {//8
        "000000",
        "011110",
        "010010",
        "011110",
        "010010",
        "011110",
        "000000"
    },
    {//9
        "011110",
        "010010",
        "010010",
        "011110",
        "000010",
        "000010",
        "000010"
    }
};

int toInt(int idx){
    string tmp[7];
    for(int i=0; i<7; i++){
        tmp[i] = s[i].substr(idx*6,6);
    }
    int num = 0;
    for(int i=0; i<10; i++){
        bool same = true;
        for(int j=0; j<7; j++){
            if(nums[i][j]!=tmp[j]){
                same = false;
                break;
            }
        }
        if(same){
            num = i;
            break;
        }
    }
    return num;
}

int main() {
    for(int i=0; i<7; i++){
        cin >> s[i];
    }
    int n = s[0].size()/6;
    for(int i=0; i<n; i++){
        v.push_back(toInt(i));
    }
    if(next_permutation(v.begin(),v.end())){
        for(int i=0; i<7; i++){
            for(int j=0; j<n; j++){
                ans[i] += nums[v[j]][i];
            }
        }
        for(int i=0; i<7; i++){
            cout << ans[i] << "\n";
        }
    }
    else{
        cout << "The End";
    }
    return 0;
}