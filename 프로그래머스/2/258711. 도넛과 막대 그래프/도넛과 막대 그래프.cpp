#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> graph[1000001];
bool check[1000001];
int in[1000001];

// int parent[1000001];
// int find(int x)
// {
//     if(x==parent[x]) return x;
//     return parent[x] = find(parent[x]);
// }

// void merge(int x, int y)
// {
//     x = find(x);
//     y = find(y);
    
//     if(x!=y){
//         parent[y] = x;
//     }
// }

// bool isUnion(int x, int y)
// {
//     x = find(x);
//     y = find(y);
    
//     return x==y;
// }

void dfs(int o, int s, bool& isCircle)
{
    check[s] = true;
    for(auto next : graph[s])
    {
        if(next==o) isCircle = true;
        if(check[next]) continue;
        dfs(o,next,isCircle);
    }
}

vector<int> solution(vector<vector<int>> edges) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> answer;
    
    int createNum = 0;
    int bar = 0;
    int donut = 0;
    int eight = 0;
    
    int maxN = 0;
    int maxOut = 0;
    vector<int> twoOuts;
    //for(int i=1; i<=1000000;i++) parent[i] = i;
    
    for(auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        maxN = max(maxN,max(u,v));
        graph[u].push_back(v);
        int len = graph[u].size();
        maxOut = max(maxOut,len);
        in[v]++;
    }
    
    for(int i=1; i<=maxN; i++){
        int out = graph[i].size();
        
        // 무관한 정점 구하기(들어오는 간선 0개 && 나가는 간선 제일 많음 이상)
        if(in[i]==0 && graph[i].size()==maxOut){
            createNum = i;
        }
        // 8자 그래프의 중심 정점 구하기(나가는 간선 2개)
        if(out==2)
        {
            twoOuts.push_back(i);
        }
    }
    
    for(auto ev : twoOuts)
    {
        if(ev==createNum) continue;
        //cout << ev << endl;
        eight++;
        for(auto s : graph[ev])
        {
            bool isCircle = false;
            dfs(s,s,isCircle);
        }
    }
    
    for(auto s : graph[createNum])
    {
        if(check[s]) continue;

        bool isCircle = false;
        dfs(s,s,isCircle);
        if(isCircle) donut++;
        else bar++;
    }
    //정점들 중 나가는 간선이 2개면 -> 8자
    //정점들 중 나가는 간선이 1개면
    //-> 그리고 사이클이 있으면 -> 도넛
    //-> 사이클이 없으면 -> 막대
    
    answer.push_back(createNum); // ㄱㅊ
    answer.push_back(donut);
    answer.push_back(bar);
    answer.push_back(eight); // ㄱㅊ
    return answer;
}