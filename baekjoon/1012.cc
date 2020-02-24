#include <iostream>

using namespace std;

bool** visited;
int** map;
int M, N;

void findNeighbor(int i, int j) {
	visited[i][j] = true;
	//up
	if ( (i-1) >= 0) {
		if (map[i-1][j] == 1 && visited[i-1][j] == 0) {
			findNeighbor(i-1, j);
		}
	} 
	//right
	if ( (j+1) < N) {
		if (map[i][j+1] == 1 && visited[i][j+1] == 0) {
			findNeighbor(i, j+1);
		}
	}
	//down
	if ( (i+1) < M) {
		if (map[i+1][j] == 1 && visited[i+1][j] == 0) {
			findNeighbor(i+1, j);
		}
	}
	//left
	if ( (j-1) >= 0) {
		if (map[i][j-1] == 1 && visited[i][j-1] == 0) {
			findNeighbor(i, j-1);
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	int TC, K, X, Y;
	cin >> TC;
	for (int k = 0; k < TC; k++) {
		cin >> M >> N >> K;
		visited = new bool*[M];
		map = new int*[M];
		for (int i = 0; i < M; i++) {
			visited[i] = new bool[N]();
			map[i] = new int[N]();
		}
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			map[X][Y] = 1;
		}
		int count = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					findNeighbor(i, j);
					count++;
				}
			}
		}
		cout << count << endl;
		for (int i = 0; i < M; i++) {
			delete[] visited[i];
			delete[] map[i];
		}
		delete[] visited;
		delete[] map;
	}
}
