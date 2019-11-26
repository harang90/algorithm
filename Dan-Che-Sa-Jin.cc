// [프로그래머스] 단체사진

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
		vector<char> line{'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
		vector<char>::iterator lineIter, lineIterTwo;
		do {
			bool tracker = false;
			for (int i = 0; i < n; i++) {
				const char* rule = data[i].c_str();
				const char from = rule[0];
				const char to = rule[2];
				const char exp = rule[3];
				const char dis = rule[4];
				for (lineIter = line.begin(); lineIter != line.end(); lineIter++) {
					if (*lineIter == from) {
						for (lineIterTwo = line.begin(); lineIterTwo != line.end(); lineIterTwo++) {
							if (*lineIterTwo == to) break;
						}
						int calcDis = std::abs(std::distance(lineIter, lineIterTwo));
						if (exp == '=') { // 거리가 같음 
							if (calcDis != dis) {
								tracker = true;
								break;
							}
						} else if (exp == '>') { // 거리가 미만
							if (calcDis <= dis) {
								tracker = true;
								break;
							}
						} else { // 거리가 초과
							if (calcDis >= dis) {
								tracker = true;
								break;
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

	std::freopen("input.txt", "r", stdin);
	std::cin >> T;
	std::vector<string> data;
	T = 1;
	for (int i = 0; i < T; i++) {
//		std::cin >> n;
//		std::string line;	
//		std::getline(std::cin, line);
//		
		//TODO
		//라인을 어찌어찌하여 백터로 만들고 등등

		//TEMP
		//1 <= n <= 100
		//{A, C, F, J, M, N, R, T}
		//~
		//>, =, <
		//0 ~ 6
		data.push_back("N~F=0");
		data.push_back("R~T>2");

		std::cout << solution(n, data) << std::endl;
	}
}
