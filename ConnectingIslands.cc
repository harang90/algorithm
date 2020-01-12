#include <vector>
#include <iostream>

int solution(int n, vector<vector<int>> costs) {
	int answer{0};
	vector<int> pushedIsland;
	// 1. lowest branch
	//   1-1. from AND to 를 기록
	// 	 1-2. branch 추가
	// 2. 그 다음 lowest branch
	// 	 2-1. 연결된 islands 중 연결되는 것 있는지 판단 / 하지만 다른 연결되는 얘는 list에 없어야함
	return answer;
}

int main() {
	int n{4};
	vector<vector<int>> costs{{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
	cout << solution(n, costs) << endl;
}
