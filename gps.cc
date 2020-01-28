#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer{0};
	bool** vectorMap{new bool*[n]};
	for (int i = 0; i < n; i++) {
		vectorMap[i] = new bool[n]();
	}
	for (int i = 0; i < m; i++) {
		int from = edge_list[i][0] - 1;
		int to = edge_list[i][1] - 1;
		vectorMap[from][to] = true;
		vectorMap[to][from] = true;
	}
	vector<int>::iterator gpsLogIter;	
	for (gpsLogIter = gps_log.begin(); gpsLogIter != gps_log.end() - 1; gpsLogIter++) {
		int from = *gpsLogIter - 1;
		int to = *(gpsLogIter+1) - 1;
		if (vectorMap[from][to] == false) answer++;
	}
	return answer;
}

int main() {
	int n{7};
	int m{10};
	vector<vector<int>> edgeList{{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
	int k{6};
	vector<int> gpsLog{1, 2, 4, 6, 5, 7};
	cout << solution(n, m, edgeList, k, gpsLog) << endl;
}
