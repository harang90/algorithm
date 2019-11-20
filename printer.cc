#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return (a < b);
}

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<int>::iterator iter;
	iter = priorities.begin();
	while (1) {
		if (*iter == *std::max_element(priorities.begin(), priorities.end(), compare)) {
			answer++;
			*iter = 0;
			if (iter - priorities.begin() == location) {
				break;
			}
		}
		iter++;
		if (iter == priorities.end()) iter = priorities.begin();
	}
	return answer;
}

int main() {
	int location = 2;
	vector<int> priorities{1, 1, 9, 1, 1, 1};
	std::cout << solution(priorities, location) << std::endl;
}
