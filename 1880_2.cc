#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land) {
	int row_num = land.size();
	int col_num = 4;

	// 최초값
	vector<int> old_max;
	for (int i = 0; i < col_num; i++) {
		oldLast.push_back(land[0][i]);
	}
	// 전 step에서 온 값 + 자신값 = max

	// print land[n-1][]

	for (int i = 1; i < row_num; i++) {
		vector<int> new_max;
	}
	std::max();

	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		int numberOfRows;
		cin >> numberOfRows;
		vector<vector<int>> land;
		for (int i = 0; i < numberOfRows; i++) {
			vector<int> row;
			for (int j = 0; j < 4; j++) {
				int num;
				cin >> num;
				row.push_back(num);
			}
			land.push_back(row);
		}
		std::cout << solution(land) << std::endl;
	}
}
