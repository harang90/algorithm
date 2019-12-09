#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> gLand;
int gMax;

void getTotal(int cur, int last, int n, int total) {
//	std::cout << "getTotal called\n";
//	std::cout << "cur = " << cur << "last = " << last << "n = " << n << "total = " << total;
	if (cur == n) {
		if (gMax < total) gMax = total;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (last != i) {
			getTotal(cur+1, i, n, total + gLand[cur][last]);
		}
	}
}

int solution(vector<vector<int>> land) {
	gLand = land;
	int answer = 0;

	//std::cout << "size = " << land.size() << std::endl;	
	for (int i = 0; i < 4; i++) {
		getTotal(0, i, land.size(),0);		
	}
	return gMax;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		gMax = -1;
		int numberOfRows;
		cin >> numberOfRows;
		vector<vector<int>> land;
		for (int i = 0; i < numberOfRows; i++) {
			vector<int> row;
			for (int j = 0; j < 4; j++) {
				int num;
				cin >> num;
				//std::cout << num << " ";
				row.push_back(num);
			}
			land.push_back(row);
			//std::cout << "\n";
		}
		std::cout << solution(land) << std::endl;
	}
}
