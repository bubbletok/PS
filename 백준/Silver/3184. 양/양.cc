#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;
using pr = pair<int, int>;
int r, c;
char arr[251][251];
bool check[251][251];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ts, tw;
void bfs(int x, int y) {
	check[y][x] = true;
	queue<pr> q;
	q.push({ x,y });
	int sheep = 0;
	int wolf = 0;
	while (!q.empty())
	{
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		if (arr[fy][fx] == 'o') sheep++;
		else if (arr[fy][fx] == 'v') wolf++;
		for (int i = 0; i < 4; i++)
		{
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c)
			{
				if (arr[ny][nx] != '#' && !check[ny][nx])
				{
					check[ny][nx] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (sheep == 0 && wolf == 0) return;

	if (sheep > wolf)
	{
		tw -= wolf;
	}
	else {
		ts -= sheep;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> r;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'o') ts++;
			else if (arr[i][j] == 'v') tw++;
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++)
		{
			if (!check[i][j] && arr[i][j]!='#')
			{
				bfs(j, i);
			}
		}
	}
	cout << ts << " " << tw;
	return 0;
}