#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool** visited;
vector<string> map;	
vector<int> groupPoints;

int findNeighbor(int depth, int i, int j, int N) {
	visited[i][j] = true;
	depth++;
	//up
	if ( (i-1) >= 0) {
		if (map[i-1][j] == '1' && visited[i-1][j] == 0) {
			depth = findNeighbor(depth, i-1, j, N);
		}
	} 
	//right
	if ( (j+1) < N) {
		if (map[i][j+1] == '1' && visited[i][j+1] == 0) {
			depth = findNeighbor(depth, i, j+1, N);
		}
	}
	//down
	if ( (i+1) < N) {
		if (map[i+1][j] == '1' && visited[i+1][j] == 0) {
			depth = findNeighbor(depth, i+1, j, N);
		}
	}
	//left
	if ( (j-1) >= 0) {
		if (map[i][j-1] == '1' && visited[i][j-1] == 0) {
			depth = findNeighbor(depth, i, j-1, N);
		}
	}
	return depth;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	visited = new bool*[N];
	for (int i = 0; i < N; i++) {
		string in;
		cin >> in;
		map.push_back(in);
		visited[i] = new bool[N]();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && visited[i][j] == 0) {
				int point = findNeighbor(0, i, j, N);
				groupPoints.push_back(point);
			}
		}
	}
	sort(groupPoints.begin(), groupPoints.end());
	cout << groupPoints.size() << endl;
	for (int i = 0; i < groupPoints.size(); i++) {
		cout << groupPoints[i] << endl;
	}
	for (int i = 0; i < N; i++) {
		delete[] visited[i];
	}
}
