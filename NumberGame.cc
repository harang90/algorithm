// [프로그래머스] 숫자 게임

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	vector<int>::iterator B_iter = B.begin();
	for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter++) {
		while (B_iter != B.end()) {
			if (*B_iter >= *iter) {
				answer++;
				B_iter++;
				break;
			}
			B_iter++;
		}
		if (B_iter == B.end()) break;
	}
	return answer;
}

int main() {
	vector<int> A{5,1,3,7};
	vector<int> B{2,2,6,8};
	std::cout << solution(A, B) << std::endl;
}
