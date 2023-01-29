//골4문제, 9분48초
//백트래킹
#include <iostream>
using namespace std;
bool check[21][21], wcheck[27];
int r,c, mv = 0;
char arr[21][21];
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

void bc(int x, int y, int cnt){
    for(int i=0; i<4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx>=0 && yy>=0 && xx<c && yy<r){
            if(!check[yy][xx] && !wcheck[arr[yy][xx]-'A']){
                check[yy][xx] = true;
                wcheck[arr[yy][xx]-'A'] = true;
                bc(xx,yy,cnt+1);
                check[yy][xx] = false;
                wcheck[arr[yy][xx]-'A'] = false;
            }
        }
    }
    mv = cnt > mv ? cnt : mv;
    return;
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    check[0][0] = true;
    wcheck[arr[0][0]-'A'] = true;
    bc(0,0,1);
    cout << mv;
    return 0;
}