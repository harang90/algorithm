#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
	// max를 구한다
	// max를 포함하는 routes를 제한다
	// routes가 0이 되면 return;

	int answer{0};
	while (routes.size()) {
		for (int i = 0; i < routes.size(); i++) {
			for
			routes[i][0];
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> routes{{-20,15},{-14,-5}, {-18,-13}, {-5,-3}};
	std::cout << solution(routes) << std::endl;
	return EXIT_SUCCESS;
}
