#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	int row_size = arr1.size();
	int col_size = arr2[0].size();
	vector<int> element;
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			int sum = 0;
			for (int k = 0; k < arr2.size(); k++) {
				sum += arr1[i][k] * arr2[k][j];
			}
			element.push_back(sum);
		}
		answer.push_back(element);
		element.clear();
	}
	return answer;
}

int main() {
	vector<vector<int>> arr1{{1, 4}, {3, 2}, {4, 1}};
	vector<vector<int>> arr2{{3, 3}, {3, 3}};
	vector<vector<int>> answer{solution(arr1, arr2)};
	vector<vector<int>>::iterator iter;
	for (iter = answer.begin(); iter != answer.end(); iter++) {
		vector<int>::iterator nest_iter;
		for (nest_iter = iter->begin(); nest_iter != iter->end(); nest_iter++) {
			std::cout << *nest_iter << " ";
		}
		std::cout << "\n";
	}
}
