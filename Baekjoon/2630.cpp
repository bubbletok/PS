#include <iostream>
using namespace std;
int n,wh=0,bl=0;
int arr[129][129] = {0};

void f(int x1, int y1, int x2, int y2){
    bool isSame = true;
    for(int i=y1; i<=y2; i++){
        for(int j=x1; j<=x2; j++){
            if(arr[y1][x1] != arr[i][j]){
                isSame = false;
                break;
            }
        }
    }
    if(isSame){
        if(arr[y1][x1]) bl++;
        else wh++;
    }
    else{
    	int midx = (x1+x2)/2, midy = (y1+y2)/2;
        f(x1,y1,midx,midy);
        f(midx+1,y1,x2,midy);
        f(x1,midy+1,midx,y2);
        f(midx+1,midy+1,x2,y2);
    }
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    f(1,1,n,n);
    cout << wh << endl << bl;
    return 0;
}