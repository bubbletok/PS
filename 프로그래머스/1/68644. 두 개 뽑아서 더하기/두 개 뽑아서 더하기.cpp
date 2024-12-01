#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bool check[201] = {false};
    int n = numbers.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int x = numbers[i]+numbers[j];
            if(check[x]) continue;
            answer.push_back(x);
            check[x] = true;
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}