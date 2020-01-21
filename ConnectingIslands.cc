#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int> > costs) {
	int answer{0};
	bool* boolList{new bool[n]()};
	sort(costs.begin(), costs.end(), [](const vector<int> & a, const vector<int> & b) {
		return a.at(2) < b.at(2);
	});
	for (auto iter = costs.begin(); iter != costs.end(); iter++) {
		int from = iter->at(0);		
		int to = iter->at(1);
		if ((boolList[from] == true) && (boolList[to] == true)) {
			continue;
		} else {
			if (boolList[from] == true) {
				boolList[to] = true;
			} else if (boolList[to] == true) {
				boolList[from] = true;
			} else {
				boolList[from] = true;
				boolList[to] = true;
			}
			answer += iter->at(2);
		}
	}
	return answer;
}

int main() {
	int n{4};
	vector<vector<int>> costs{{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
	cout << solution(n, costs) << endl;
}
