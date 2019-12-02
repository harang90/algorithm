//[프로그래머스]
//점프와 순간 이동

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> gMin;

int getMin(int n) {
	if (gMin[n] != 0) return gMin[n];
	if (n % 2 == 0) {
		if (getMin(n/2) < (getMin(n-1) + 1)) {
			gMin[n] = getMin(n/2);
		} else {
			gMin[n] = getMin(n-1) + 1;
		}
	} else {
		gMin[n] = getMin(n-1) + 1;
	}
	return gMin[n];
}

int solution(int n) {
    int answer = 0;
		gMin.reserve(n+1);
		for (int i = 1; i <= n; i++) {
			gMin[i] = 0;
		}
		gMin[1] = 1;
		gMin[2] = 1;
		answer = getMin(n);	
		gMin.clear();
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
