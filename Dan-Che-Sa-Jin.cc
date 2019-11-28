// [프로그래머스] 단체사진

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
		vector<char> line{'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
		vector<char>::iterator lineIter, lineIterTwo;
		bool tracker;
		do {
			tracker = false;
			for (int i = 0; i < n; i++) {
				const char* rule = data[i].c_str();
				const char from = rule[0];
				const char to = rule[2];
				const char exp = rule[3];
				const char dis = atoi(&rule[4]);
				for (lineIter = line.begin(); lineIter != line.end(); lineIter++) {
					if (*lineIter == from) {
						for (lineIterTwo = line.begin(); lineIterTwo != line.end(); lineIterTwo++) {
							if (*lineIterTwo == to) break;
						}
						int calcDis = std::abs(lineIter - lineIterTwo) - 1;
						if (exp == '=') { // 거리가 같음 
							if (calcDis != dis) {
								tracker = true;
							}
						} else if (exp == '>') { // 거리가 더 크기 원함
							if (calcDis <= dis) {
								tracker = true;
							}
						} else { // 거리가 더 작기 원함
							if (calcDis >= dis) {
								tracker = true;
							}
						}
						break;
					}
				}
				if (tracker) break;
			}
			if (!tracker) answer++;
		} while (std::next_permutation(line.begin(), line.end()));
    return answer;
}

int main () {
	int T;
	int n;
	std::string line;

	std::freopen("input.txt", "r", stdin);
	std::cin >> T;
	std::vector<string> data;
	for (int i = 0; i < T; i++) {
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> line;
			if (j == 0) {
				line.erase(0, 1);
			}
			line.erase(line.end()-1);
			data.push_back(line);
		}
		std::cout << solution(n, data) << std::endl;
		data.clear();
	}
}
