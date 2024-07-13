#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int,int>> v;
bool check[12] = {false};
/*string stars[12] = {"물병","물고기","양","황소","쌍둥이","게","사자", "처녀", "천칭", "전갈", "사수", "염소"};*/
bool checkValid(int d, int s, int e){
    return (s<=d&&d<=e);
}

int days[12][2] = {
    {20,18},
    {19,20},
    {21,19},
    {20,20},
    {21,21},
    {22,22},
    {23,22},
    {23,22},
    {23,22},
    {23,22},
    {23,21},
    {22,19}
};

void starsCheck(int m, int d, int oper){
    int ds = m*31 + d;
    bool done = false;
    for(int i=1; i<=11; i++){
        int s = i*31 + days[i-1][0];
        int e = (i+1)*31 + days[i-1][1];
        if(checkValid(ds,s,e)){
            if(oper==1){
                check[i-1] = true;
            }
            else if(oper==2){
                if(!check[i-1]){
                    v.push_back({m,d});
                }
            }
            done = true;
            break;
        }
    }
    if(!done){
        if(oper==1){
            check[11] = true;
        }
        else if(oper==2){
            if(!check[11]){
                v.push_back({m,d});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i=0; i<7; i++){
        int m, d;
        cin >> m >> d;
        starsCheck(m,d,1);
    }
    cin >> n;
    for(int i=0; i<n; i++){
        int m, d;
        cin >> m >> d;
        starsCheck(m,d,2);
    }
    if(v.size()==0){
        cout << "ALL FAILED";
    }
    else{
        sort(v.begin(),v.end());
        for(auto i : v){
            cout << i.first << " " << i.second << "\n";
        }
    }
    return 0;
}