// [프로그래머스] 방문 길이

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

int solution (std::string dirs) {
	int answer{0};
	// 1. direction 판별
	// 2. edge 판별
	//	2-1. U: y가 5이면 무시, D: y가 -5이면 무시, L: x가 -5이면 무시, R: x가 5이면 무시
	// 3. available 판별
	//	3-1. D이면 다운에서 해당 pos가 있는지 확인! 없으면 ++.
	// 	3-2. D이면 UP에서 (posX, posY-1)이 있는지 확인!
	// 4. push back으로 pair를 넣자. (dirs를 받았을 때 어디서 어느 dir로 가는지 적어둔다.)

	std::pair<int, int> lastPos, nextPos;
	std::vector<std::pair<int, int>> U, D, L, R;

	lastPos.first = 0;
	lastPos.second = 0;
	for (int i = 0; i < dirs.length(); i++) {
		if (dirs[i] == 'U') {
			if (lastPos.second == 5) continue;
			nextPos.first = lastPos.first;
			nextPos.second = lastPos.second + 1;
			if ((std::find(U.begin(), U.end(), lastPos) == U.end()) && (std::find(D.begin(), D.end(), nextPos) == D.end())) {
				answer++;
				U.push_back(lastPos);	
			}
			lastPos = nextPos;
		} else if (dirs[i] == 'D') {
			if (lastPos.second == -5) continue;
			nextPos.first = lastPos.first;
			nextPos.second = lastPos.second - 1;
			if ((std::find(U.begin(), U.end(), nextPos) == U.end()) && (std::find(D.begin(), D.end(), lastPos) == D.end())) {
				answer++;
				D.push_back(lastPos);	
			}
			lastPos = nextPos;
		} else if (dirs[i] == 'L') {
			if (lastPos.first == -5) continue;
			nextPos.first = lastPos.first - 1;
			nextPos.second = lastPos.second;
			if ((std::find(R.begin(), R.end(), nextPos) == R.end()) && (std::find(L.begin(), L.end(), lastPos) == L.end())) {
				answer++;
				L.push_back(lastPos);	
			}
			lastPos = nextPos;
		} else {
			if (lastPos.first == 5) continue;
			nextPos.first = lastPos.first + 1;
			nextPos.second = lastPos.second;
			if ((std::find(R.begin(), R.end(), lastPos) == R.end()) && (std::find(L.begin(), L.end(), nextPos) == L.end())) {
				answer++;
				R.push_back(lastPos);	
			}
			lastPos = nextPos;
		}
	}
	return answer;
}

int main () {
	std::string dirs{"ULURRDLLU"};
	std::cout << solution(dirs) << std::endl;
}
