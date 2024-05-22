#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	string word;
	getline(cin, word);
	int cnt = 0;
	for (int i = 0; i < s.size();) {
		bool found = true;
		for (int j = 0; j <word.size(); j++) {
			if (s[i + j] != word[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			cnt++;
			i += word.size();
		}
		else {
			i++;
		}
	}
	cout << cnt;
	return 0;
}