#include <iostream>

using namespace std;

char ** dir;
int ** map;
bool* visited;
int N;

void updateMap(int start, int i, int j) {	
	map[start][j] = 1;
	visited[j] = true;
	for (int k = 0; k < N; k++) {
		if (dir[j][k] == '1' && visited[k] == false) updateMap(start, j, k);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> N;
	dir = new char*[N];
	map = new int*[N];

	//get input
	for (int i = 0; i < N; i++) {
		dir[i] = new char[N]();
		map[i] = new int[N]();
		for (int j = 0; j < N; j++) {
			cin >> dir[i][j];
		}
	}
	
	// 문제 접근 방식 - DFS
	// 1. 각 꼭지점 0부터 N-1까지 시작했을 때를 가정하고 각각에 대해서 갈 수 있는 꼭지점을 DFS를 사용해 구한다.
		// 1-1. 0에서 시작해서 1로 가고 1에서 2로 가는 길이 있다면 2로 가고 0 또한 2로 갈 수 있다고 기록한다.

	for (int i = 0; i < N; i++) {
		visited = new bool[N]();
		for (int j = 0; j < N; j++) {
			if (dir[i][j] == '1' && visited[j] == false) {
				updateMap(i, i, j);
			}
		}
		delete visited;
	}

	//produce output
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		delete[] dir[i];
		delete[] map[i];
	}
	delete[] map;
	delete[] dir;
	return 0;
}
