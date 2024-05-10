#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

bool prev_permutation(vector<int> &a){
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) i -= 1; //(1번)
	if (i <= 0) return false;
	int j = n - 1;
	while (a[j] >= a[i - 1]) j -= 1; //(2번)
	swap(a[i - 1], a[j]); //(3번)
	j = n - 1;
	while (i < j) { //4번)
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}

int main() {
	cin >> n;
	vector<int> per;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		per.push_back(a);
	}
	bool exist = prev_permutation(per);
	if(!exist){
		cout << -1;
	}
	else{
		for(auto i : per){
			cout << i << " ";
		}
	}
	return 0;
}