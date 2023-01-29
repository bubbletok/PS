//골드5 문제, 13분8초
//백트래킹
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l,c;
char arr[17];
bool check[17];
vector<char> v;
void bt(int start, int cnt){
    if(cnt==l){
        int vol=0, con=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u')
                vol++;
            else
                con++;
        }
        if(vol >=1 && con >=2){
            for(int i=0; i<v.size(); i++){
                cout << v[i];
            }
            cout << endl;
        }
        return;
    }
    for(int i=start; i<c; i++){
        if(!check[i]){
            check[i] = true;
            v.push_back(arr[i]);
            bt(i,cnt+1);
            check[i] = false;
            v.pop_back();
        }
    }
}
int main(){
    cin >> l >> c;
    for(int i=0; i<c; i++){
        cin >> arr[i];
    }
    sort(arr,arr+c);
    bt(0,0);
    //a t c i s w
    //a c i s t w
}