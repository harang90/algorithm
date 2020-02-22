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

	// get string
	for (int i = 0; i < N; i++) {
		string in;
		cin >> in;
		map.push_back(in);
		visited[i] = new bool[N]();
	}

	// 접근 방식 (DFS)
	// 1. Depth를 사용해서 연결되는 칸들의 수를 구함
	// 	- 주위에 1이 있다면 해당 칸으로 가고 Depth는 1 증가한다
	// 	- 주위에 1이 없다면 최종 Depth를 반환한다
	// 2. Visited를 두어 그룹을 나누는데 사용함
	//	- 최상단에서 보았을 때 이미 이전 그룹에 속한 칸들은 이미 visit 했기 때문에 visited 안한 칸을 만났을 때는 새로운 그룹이라고 봐도 좋다

	// dfs (recursive)
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
