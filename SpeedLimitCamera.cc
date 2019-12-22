#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
	//trial 1 

	// max를 구한다
	// max를 포함하는 routes를 제한다
	// routes가 0이 되면 return;

	// trial 2

	// 순서대로 하나 뽑는다
	// 좌우 중 가장 많은 곳 한곳 고른다.
	// 겹치는 곳은 지운다.

	int answer{0};
	int num;
	for (int k = 0; k < routes.size(); k++) {
		if (routes[k][0] > routes[k][1]) {
			std::swap(routes[k][0], routes[k][1]);
		}
	}
	while (routes.size()) {
		vector<int> list[2];
		int num[2]{0,0};
		for (int k = 0; k < routes.size(); k++) {
			for (int i = 0; i < 2; i++) {
				if (routes[k][0] <= routes[0][i] && routes[0][i] <= routes[k][1]) {
					list[i].push_back(k);
					num[i]++;
				}
			}
		}
		if (num[0] > num[1]) {
			for (int i = 0; list[0].size(); i++) {
				routes.erase(routes.begin() + list[0][i]);
			}
		} else {
			for (int i = 0; list[1].size(); i++) {
				routes.erase(routes.begin() + list[1][i]);
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
