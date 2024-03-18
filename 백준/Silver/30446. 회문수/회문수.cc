#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

long long int changeToInt(string& s)
{
	long long int sum = 0;
	for (int i=0; i < s.size(); i++)
	{
		sum += (s[s.size() - 1 - i] - '0') * pow(10, i);
	}
	return sum;
}

string reverse(string& s) {
	string tmp = "";
	for (int i = s.size() - 1; i >= 0; i--)
	{
		tmp += s[i];
	}
	return tmp;
}

string split(string& s, int start, int end) {
	string tmp = "";
	for (int i = start; i <= end; i++){
		tmp += s[i];
	}
	return tmp;
}

bool AllZero(string& s) {
	for(int i=1; i<s.size(); i++){
		if (s[i] != '0') return false;
	}
	return true;
}

int main() {
	string s;
	cin >> s;

	int dp[11] = { 0,9,9,90,90,900,900,9000,9000,90000,90000 };
	long long int ans = 0;
	
	if (s.size() == 1)
	{
		ans = s[0] - '0';
	}
	else {
		long long int num = changeToInt(s);
		for (int i = 1; i < s.size(); i++) {
			ans += dp[i];
		}
		if (!(s[0] == '1' && AllZero(s)))
		{
			string frontHalf;
			string backHalf;

			if (s.size() % 2 == 0) {
				frontHalf = split(s, 0, s.size() / 2 - 1);
				backHalf = split(s, s.size() / 2, s.size());
			}
			else {
				frontHalf = split(s, 0, s.size() / 2);
				backHalf = split(s, s.size() / 2, s.size());
			}

			string frontHalfReverse = reverse(frontHalf);
			
			int cnt = 0;

			if (frontHalfReverse <= backHalf)	
			{
				cnt = changeToInt(frontHalf);
			}
			else {
				cnt = changeToInt(frontHalf) - 1;
			}
			ans += cnt - pow(10, frontHalf.size() - 1) + 1;
		}
	}

	cout << ans;
	return 0;
}