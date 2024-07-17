// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<string> ans;
    if(n>=3 && m<=4) ans.push_back("TroyMartian");
    if(n<=6 && m>=2) ans.push_back("VladSaturnian");
    if(n<=2 && m<=3) ans.push_back("GraemeMercurian");
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }
    return 0;
}