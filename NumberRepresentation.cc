// 숫자의 표현
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
		int addNum;
		int total;
		for (int i = 1; i <= n; i++) {
			addNum = i;
			total = 0;
			while (1) {
				total += addNum;	
				if (total == n) {
					answer++;
				}
				if (total >= n) break;
				addNum++;
			}
		}
    return answer;
}

int main() {
	int T, test_case;
	freopen("input.txt", "r", stdin);
	cin >> T;
	int n;
	for (test_case = 0; test_case < T; test_case++) {
		cin >> n;
		std::cout << solution(n) << std::endl;
	}
}
