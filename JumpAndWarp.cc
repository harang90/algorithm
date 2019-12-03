//[프로그래머스]
//점프와 순간 이동

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
		int answer{0};
		while (n != 0) {
			if (n % 2) {
				answer++;
				n -= 1;
			}
			else n /= 2;
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
		cout << solution(n) << std::endl;
	}
}
