#include <iostream>
using namespace std;
int n,m;
long long int nu,de;
long long int dp[21][21];


long long int fact(int n){
    if(n==1)
        return 1;
    return n * fact(n-1);
}

long long int gcd(long long int a, long long int b){
	return b ? gcd(b,a%b) : a;
}
int main(){
    cin >> n >> m;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 2;
    for(int i=3; i<=n; i++){
    	for(int j=1; j<=i; j++){
    		if(j==1)
    			dp[i][j] = (i-1)*dp[i-1][j];
    		else if(i==j)
    			dp[i][j] = fact(i);
    		else 
    			dp[i][j] = (i-1)*dp[i-1][j] + dp[i-1][j-1];
    	}
    }
    nu = dp[n][m];
    de = fact(n);
    long long int g = gcd(nu,de);
    nu /= g;
    de /= g;
    cout << nu << "/" << de;
    return 0;
}