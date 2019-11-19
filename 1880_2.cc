#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
	int row_num = land.size();
	int col_num = 4;

	vector<int> old_max(col_num, 0);
	for (int i = 0; i < col_num; i++) {
		old_max[i] = land[0][i];
	}
	for (int i = 1; i < row_num; i++) {
		vector<int> new_max(col_num, 0);
		for (int j = 0; j < col_num; j++) {
			int total_max = 0;
			for (int k = 0; k < col_num; k++) {
				if ((k != j) && (total_max < old_max[k])) total_max = old_max[k];
			}			
			new_max[j] = total_max + land[i][j];
		}
		old_max = new_max;
	}
	return *std::max_element(old_max.begin(), old_max.end());
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
