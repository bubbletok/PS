#include <iostream>
using namespace std;
int n,m,arr[51][51], cnt = 0;
int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
int ans[51][51];
bool isClear[51][51] = {{false,}};
void clear(int r, int c, int d){
    if(!isClear[r][c]){
        cnt++;
        isClear[r][c] = true;
        ans[r][c] = cnt;
    }
    bool left = false;
    for(int i=0; i<4; i++){
        int x = c+dx[i], y = r+dy[i];
        if(x>0 && y>0 && x<=m && y<=n){
            if(!isClear[y][x]){
                left = true;
                break;
            }
        }
    }
    if(!left){
        int x = c - dx[d], y = r - dy[d];
        if((x < 0 || y<0 || x>=m || y>=n) || arr[y][x] == 1){
            return;
        }
        else
            clear(y,x,d);
    }
    else{
        d = d == 0 ? 3 : d-1;
        int x = c+dx[d], y = r+dy[d];
        if(x>=0 && y>=0 && x<m && y<n){
            if(!isClear[y][x]){
                clear(y,x,d);
            }
            else
                clear(r,c,d);
        }
    }
}

int main(){
    int r,c,d;
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                isClear[i][j] = true;
        }
    }
    clear(r,c,d);
    cout << cnt;
}