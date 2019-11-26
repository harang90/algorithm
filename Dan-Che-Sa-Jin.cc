// [프로그래머스] 단체사진

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    return answer;
}

int main () {
	int T;
	int n;

	std::freopen("input.txt", "r", stdin);
	std::cin >> T;
	std::vector<string> data;
	for (int i = 0; i < T; i++) {
//		std::cin >> n;
//		std::string line;	
//		std::getline(std::cin, line);
//		
		//TODO
		//라인을 어찌어찌하여 백터로 만들고 등등

		//TEMP
		data.push_back("N~F=0");
		data.push_back("R~T>2");

		std::cout << solution(n, data) << std::endl;
	}
}
