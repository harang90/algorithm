//[BOJ] 키 순서

// 접근 방법
// 1. 플로이드를 돌린다
// 2. 해당 VERTEX까지 올 수 있는 VERTEX 개수를 샌다 (자신 제외)
// 3. 해당 VERTEX에서 갈 수 있는 VERTEX 개수를 샌다 (자신 제외)
// 4. 둘 합이 VERTEX - 1 이면 해당 노트는 순서를 정할 수 있다.

#include <cstdio>
#include <iostream>

int main() {
	freopen("input.txt", "r", stdin);	

	int N, M;
	std::cin >> N >> M;	
	bool** rows;
	rows = new bool* [N];
	for (int i = 0; i < N; i++) {
		rows[i] = new bool [N];
	}
	for (int i = 0; i < M; i++) {
		int from, to;
		std::cin >> from >> to;
		rows[from-1][to-1] = true;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((rows[i][k] == true) && (rows[k][j] == true)) rows[i][j] = true;
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << rows[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/
	int answer{0};
	for (int k = 0; k < N; k++) {
		int num{0};
		for (int i = 0; i < N; i++) {
			if ((i != k) && ((rows[i][k] == true) || (rows[k][i] == true))) {
				num++;
			}
		}	
		if (num == (M-1)) answer++;
	}
	std::cout << answer << std::endl;
	return EXIT_SUCCESS;
}
