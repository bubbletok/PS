#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
int prime(int a){
	int cnt = 0;
	for(int i=2; i*i<=a; i++){
		if(a%i==0)
			cnt++;
		if(cnt>=1)
			break;
	}
	if(a != 1 && cnt==0)
		return 1;
	else
		return 0;
} 

int main() {
	cin >> n;
	for(int i=2; i<=2000003; i++){
		if(prime(i))
			v.push_back(i);
	}
	int sum[400000];
	if(!v.empty())
		sum[0] = v[0];
	for(int i=1; i<v.size(); i++)
		sum[i] = sum[i-1] + v[i];
	int s = 0, e = 0, len = v.size();
	int cnt = 0;
	int tmp = sum[0];
	while(s<len && e<len){
		tmp = sum[e]-sum[s]+v[s];
		if(tmp==n){
			cnt++;
		}
		if(tmp<=n)
			e++;
		else
			s++;
	}
	if(n>2000003 && prime(n))
		cnt += 1;
	cout << cnt;
	return 0;
}

//에라토스테네스 체 사용
// #include <iostream>
// #include <vector>
// using namespace std;
// int n;
// vector<int> v;
// vector<bool> check;

// int main() {
// 	cin >> n;
// 	check.resize(n+1,true);
//     for(int i=2; i*i<=n; i++){
//         if(check[i]){
//             for(int j=i+i; j<=n; j+=i)
//                 check[j] = false;
//         }
//     }
//     for(int i=2; i<=n; i++)
//         if(check[i])
//             v.push_back(i);
// 	int cnt = 0, s = 0, e = 0, len = v.size(), sum = 0;
// 	while(1){
// 		if(sum>=n)
// 			sum -= v[s++];
// 		else if(e==len)
// 			break;
// 		else
// 			sum += v[e++];
// 		if(sum==n)
// 			cnt++;
// 	}
// 	cout << cnt;
// 	return 0;
// }