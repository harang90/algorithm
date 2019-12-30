// [프로그래머스] 숫자 게임

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	std::sort(A.begin(), A.end());
	//std::sort();
	return answer;
}

int main() {
	vector<int> A{5,1,3,7};
	vector<int> B{2,2,6,8};
	std::cout << solution(A, B) << std::endl;
}
