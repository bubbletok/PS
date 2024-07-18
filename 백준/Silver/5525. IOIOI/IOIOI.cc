#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using ll = long long;
int n, m;
vector<int> getPi(string& p) {
	vector<int> pi(p.size(),0);
	// KMP로 자기 자신을 찾는다.
	int begin = 1;
	int matched = 0; //현재 일치된 문자열 길이
	while (begin + matched < p.size()) {
		if (p[begin + matched] == p[matched]) {
			++matched;
			pi[begin+matched-1] = matched;
		}
		else {
			if (matched == 0) {
				++begin;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmp(string& s, string& p) {
	vector<int> idx;
	vector<int> pi = getPi(p);
	int begin = 0;
	int matched = 0;

	while (begin <= s.size() - p.size()) {
		if (matched < p.size() && s[begin + matched] == p[matched]) {
			++matched;
			if (matched == p.size()) {
				idx.push_back(begin);
			}
		}
		else {
			if (matched == 0) {
				++begin;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return idx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	string s;
	cin >> s;
	string p = "";
	for (int i = 0; i < n; i++) {
		p += 'I';
		p += 'O';
	}
	p += 'I';
	vector<int> ans;
	ans = kmp(s, p);
	cout << ans.size();
	return 0;
}