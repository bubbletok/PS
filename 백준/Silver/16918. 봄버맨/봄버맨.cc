#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
char arr[201][201];
int t[201][201];
int r, c, n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void InstallBoomb()
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '.') {
				arr[i][j] = 'O';
				t[i][j] = 0;
			}
		}
	}
}

void Boomb(int x, int y)
{
	arr[y][x] = '.';
	t[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < c && 0 <= ny && ny < r && t[ny][nx]!=3) {
			arr[ny][nx] = '.';
			t[ny][nx] = 0;
		}
	}
}

void Process()
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'O') t[i][j]++;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'O' && t[i][j] == 3) {
				Boomb(j, i);
			}
		}
	}
}

void print()
{
	//cout << "Time: " << n << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	//cout << endl;
}

void printtime()
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << t[i][j];
		}
		cout << "\n";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	Process(); n--;
	while (1)
	{
		if (n <= 0) break;
		
		//t+2: install boomb
		Process(); n--;
		InstallBoomb();

		if (n <= 0) break;

		//t+3: doing nothing
		Process(); n--;
		//print();
		//printtime();

		if (n <= 0) break;
	}
	print();
	
	return 0;
}