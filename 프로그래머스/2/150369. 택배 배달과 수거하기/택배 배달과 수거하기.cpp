#include <string>
#include <vector>
#include <iostream>
using namespace std;

void print(vector<int>& d, vector<int>& p)
{
    for(auto i : d) cout << i << " ";
    cout << endl;
    for(auto i : p) cout << i << " ";
    cout << endl << endl;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d = 0;
    int p = 0;

    for(int i=n-1; i>=0; i--)
    {
        int cnt = 0; // i번째 처리하는데 왕복한 횟수
        d -= deliveries[i]; // i번째 배달 완료했다 가정
        p -= pickups[i]; // i번째 수거 완료했다 가정

        while(d<0 || p<0) // i번재를 처리하기 위해 왕복 진행.
        {
            d += cap;
            p += cap;
            cnt++;
        }

        answer += (i+1)*2*cnt; // 결과에 값 추가 => i번째를 cnt만큼 왕복해서 처리함
    }
    //print(deliveries,pickups);
    //cout << "Last: " << curLast << endl;
    return answer;
}