#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int n;
int arr[21][21];
int sharkSize = 2;

struct fish {
	int dist;
	int x;
	int y;
};

struct Pos {
	int x;
	int y;
	int dist;
};

vector<fish> fishes;
void FindSharkPos(int& x, int& y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 9) {
				x = j;
				y = i;
				return;
			}
		}
	}
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool CheckPos(int x, int y, bool visit[][21]) {
	return (0 <= x && x < n && 0 <= y && y < n && !visit[y][x]);
}

bool FindFish(int x, int y, bool visit[][21]) {
	queue<Pos> q;
	visit[y][x] = true;
	q.push({x,y,0});
	while (!q.empty()) {
		int fx = q.front().x;
		int fy = q.front().y;
		int fd = q.front().dist;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			int nd = fd + 1;
			if (!CheckPos(nx, ny,visit)) continue;
			if (arr[ny][nx] > sharkSize) continue;
			else {
				if (arr[ny][nx] < sharkSize && arr[ny][nx] != 0) {
					fishes.push_back({ nd,nx,ny });
				}
				q.push({ nx,ny,nd});
				visit[ny][nx] = true;
			}
		}
	}
	return (fishes.size() > 0);
}

vector<fish> FindShortestFishes(vector<fish>& fishes) {
	vector<fish> temp;
	int minDist = fishes[0].dist;
	for (int i = 0; i < fishes.size(); i++) {
		if (minDist > fishes[i].dist) {
			minDist = fishes[i].dist;
		}
	}
	for (int i = 0; i < fishes.size(); i++) {
		if (minDist == fishes[i].dist) {
			temp.push_back(fishes[i]);
		}
	}
	return temp;
}

vector<fish> FindNorthestFishes(vector<fish>& fishes) {
	vector<fish> temp;
	int minY = fishes[0].y;
	for (int i = 0; i < fishes.size(); i++) {
		if (minY > fishes[i].y) {
			minY = fishes[i].y;
		}
	}
	for (int i = 0; i < fishes.size(); i++) {
		if (minY == fishes[i].y) {
			temp.push_back(fishes[i]);
		}
	}
	return temp;
}

fish FindWestestFish(vector<fish>& fishes) {
	int minX = fishes[0].x;
	fish temp = fishes[0];
	for (int i = 0; i < fishes.size(); i++) {
		if (minX > fishes[i].x) {
			minX = fishes[i].x;
			temp = fishes[i];
		}
	}
	return temp;
}

//void PrintArea() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << arr[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int sharkX, sharkY;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int t = 0;
	int eatenNum = 0;
	FindSharkPos(sharkX, sharkY);
	while (1) {
		bool visit[21][21] = { {false} };
		fishes.clear();
		if (!FindFish(sharkX, sharkY,visit)) break;
		vector<fish> EatableFishes;
		EatableFishes = FindShortestFishes(fishes);
		EatableFishes = FindNorthestFishes(EatableFishes);
		fish EatableFish = FindWestestFish(EatableFishes);

		// eat fish
		arr[sharkY][sharkX] = 0;
		sharkX = EatableFish.x;
		sharkY = EatableFish.y;
		arr[sharkY][sharkX] = 9;
		eatenNum++;
		if (eatenNum >= sharkSize) {
			sharkSize++;
			eatenNum = 0;
		}
		t += EatableFish.dist;
	}
	cout << t;

	return 0;
}