//
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;
int arr[1000001], tmp[1000001];
stack<pair<int,int>> s;

void binary(int start, int end, int target){
	while(start < end){
		int mid = (start+end)/2;
		if(target > tmp[mid]){
			start = mid+1;
		}
		else{
			end = mid;
		}
	}
	tmp[start] = target;
	s.push(make_pair(start,target));
}

int main() {
	int n, len = 0;
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	tmp[0] = arr[0];
	s.push(make_pair(0,arr[0]));
	for(int i=1; i<n; i++){
		if(tmp[len] < arr[i]){
			tmp[++len] = arr[i];
			s.push(make_pair(len,arr[i]));
		}
		else{
			binary(0,len,arr[i]);
		}
	}
	int tmp = len;
	stack<int> st;
	while(!s.empty()){
		int tf = s.top().first, ts = s.top().second;
		if(tf == tmp){
			st.push(ts);
			tmp--;
		}
		s.pop();
	}
	cout << len+1 << endl;
	while(st.size()>1){
		cout << st.top() << " ";
		st.pop();
	}
	cout << st.top();
	return 0;
}

//DP, 스택
#include <iostream>
#include <stack>
using namespace std;
int arr[1001], dp[1001], path[1001];
stack<int> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, len = 0;
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	dp[0] = arr[0];
	path[0] = 0;
	for(int i=1; i<n; i++){
		for(int j=0; j<=len; j++){
			if(dp[j] >= arr[i]){
				dp[j] = arr[i];
				path[i] = j;
				break;
			}
			if(dp[j] < arr[i]){
				if(j==len){
					dp[++j] = arr[i];
					len++;
					path[i] = j;
				}
			}
		}
	}
	cout << len+1 << endl;
	int tmp = len;
	for(int i=n-1; i>=0; i--){
		if(path[i]==tmp){
			s.push(arr[i]);
			tmp--;
		}
	}
	while(s.size()>1){
		cout << s.top() << " ";
		s.pop();
	}
	cout << s.top();
	return 0;
}
