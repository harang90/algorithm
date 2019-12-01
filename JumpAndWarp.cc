//[프로그래머스]
//점프와 순간 이동

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getMin(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n % 2 == 0) {
		return getMin(n/2) < (getMin(n-1) + 1) ? getMin(n/2) : (getMin(n-1) + 1);
	} else {
		return getMin(n-1) + 1;
	}
}

int solution(int n) {
    int answer = 0;
		answer = getMin(n);	
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
