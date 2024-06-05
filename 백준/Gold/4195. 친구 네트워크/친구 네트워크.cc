#include <iostream>
#include <map>
#include <string>
using namespace std;
string find(map<string,string>& parent, string s){
	if(parent[s]==s){
		return s;
	}
	return parent[s] = find(parent, parent[s]);
}

void merge(map<string,string>& parent, string& a, string& b, map<string,int>& cnt){
	a = find(parent, a);
	b = find(parent, b);
	if(a==b) return;
	parent[b] = a;
	int sum = cnt[a]+cnt[b];
	//cout << sum << endl;
	cnt[a] = sum;
	cnt[b] = sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int f;
		cin >> f;
		map<string, string> m;
		map<string, int> cnt;
		for(int i=0; i<f; i++){
			string a, b;
			cin >> a >> b;
			if(m.find(a)==m.end()){
				m[a] = a;
			}
			if(m.find(b)==m.end()){
				m[b] = b;
			}
			if(cnt.find(a)==cnt.end()){
				//cout << a << " ";
				cnt[a] = 1;
			}
			if(cnt.find(b)==cnt.end()){
				//cout << b << " ";
				cnt[b] = 1;
			}
			merge(m,a,b,cnt);
			cout << cnt[a] << "\n";
		}
	}
	return 0;
}