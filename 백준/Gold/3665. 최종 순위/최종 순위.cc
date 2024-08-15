#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
int t;
int n, m;
int degree[501];
int graph[501][501];
bool ambi;
void topology(queue<int>& q, vector<int>& ans) {
    while (!q.empty()) {
        if (q.size() > 1) {
            ambi = true;
        }
        int f = q.front();
        ans.push_back(f);
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (graph[f][i]) {
                degree[i]--;
                if (degree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    cin >> t;
    while (t--) {
        int arr[501];
        memset(degree, 0, sizeof(degree));
        memset(graph, 0, sizeof(graph));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i != 0) {
                for (int j = 0; j < i; j++) {
                    graph[arr[i]][arr[j]] = true;
                    degree[arr[j]]++;
                }
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (graph[a][b]) {
                graph[a][b] = false;
                degree[b]--;
                graph[b][a] = true;
                degree[a]++;
            }
            else {
                graph[b][a] = false;
                degree[a]--;
                graph[a][b] = true;
                degree[b]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        ambi = false;
        vector<int> ans;
        topology(q, ans);
        if (ans.size() != n) {
            cout << "IMPOSSIBLE\n";
        }
        else if (ambi) {
            cout << "?\n";
        }
        else {
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}