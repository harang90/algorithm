#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer{0};

	// 플로이드를 써서 다른 vertex를 거쳐서라도 갈 수 있으면 edge 값 update
	// 나보다 큰 수 + 나보다 작은 수 = N-1 이면, 확실히 알 수 있는 수

	bool** rows = new bool* [n];
	for (int i = 0; i < n; i++) {
		rows[i] = new bool [n];
	}
	for (int i = 0; i < results.size(); i++) {
		int from = results[i][0];
		int to = results[i][1];
		rows[from-1][to-1] = true;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((rows[i][k] == true) && (rows[k][j] == true)) rows[i][j] = true;
			}
		}
	}
  for (int k = 0; k < n; k++) {
    int num{0};
    for (int i = 0; i < n; i++) {
      if ((i != k) && ((rows[i][k] == true) || (rows[k][i] == true))) {
        num++;
      }
    }
    if (num == (n-1)) answer++;
  }	
	return answer;
}

int main() {
	int n{5};
	vector<vector<int>> results{{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
	std::cout << solution(n, results) << std::endl;
	return EXIT_SUCCESS;
}
