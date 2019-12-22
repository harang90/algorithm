#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
	// max를 구한다
	// max를 포함하는 routes를 제한다
	// routes가 0이 되면 return;

	int answer{0};
	int max;
	int max_i;
	int max_j;
	int num;
	while (routes.size()) {
		max = 0;
		max_i = -1;
		max_j = -1;
		for (int i = 0; i < routes.size(); i++) {
			for (int j = 0; j < 2; j++) {
				num = 0;
				for (int k = 0; k < routes.size(); k++) {
					if ((routes[k][0] <= routes[i][j]) && (routes[i][j] <= routes[k][1])) {
						num++;
					}
				}
				if (num > max) {
					max = num;
					max_i = i;
					max_j = j;
				}
			}
		}
		for (int k = 0; k < routes.size(); k++) {
			if ((routes[k][0] <= routes[max_i][max_j]) && (routes[max_i][max_j] <= routes[k][1])) {
				routes.erase(routes.begin() + k);
				k--;
			}
		}
		answer++;
	}
	return answer;
}

int main() {
	vector<vector<int>> routes{{-20,15},{-14,-5}, {-18,-13}, {-5,-3}};
	std::cout << solution(routes) << std::endl;
	return EXIT_SUCCESS;
}
