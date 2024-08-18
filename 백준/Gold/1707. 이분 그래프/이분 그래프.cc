#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
using ll = long long;
int k, v, e;
int sets[20001];
bool check[20001];

void divideSet(int start, vector<int> graph[]) {
    check[start] = true;
    queue<pair<int,int>> q;
    q.push({ start,1 });
    sets[start] = 1;
    while (!q.empty()) {
        int cur = q.front().first;
        int type = q.front().second;
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (!check[next]) {
                q.push({ next,type * -1 });
                sets[next] = type * -1;
                check[next] = true;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    while (k--) {
        bool poss = true;
        memset(check, false, sizeof(check));
        memset(sets, 0, sizeof(sets));
        int V, E;
        cin >> V >> E;
        vector<int> graph[20001];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 1; i <= V; i++) {
            if (check[i]) continue;
            divideSet(i, graph);
        }
        for (int cur = 1; cur <= V; cur++) {
            for (int j = 0; j < graph[cur].size(); j++) {
                int next = graph[cur][j];
                if (sets[cur] == sets[next]) {
                    poss = false;
                    break;
                }
            }
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}