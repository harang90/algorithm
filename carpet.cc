
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int length;
	int width;
	int numBrown;
	int numCorner = 4;
	for (int i = 1; i <= red; i++) {
		if (red % i == 0) {
			width = i;
		 	length = red / i;
			numBrown = width * 2 + length * 2 + numCorner;
			if (brown == numBrown) break;
		}
	}
	answer.push_back(length+2);
	answer.push_back(width+2);
	return answer;
}

int main() {
	int brown, red;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> brown;
		cin >> red;
		vector<int> answer = solution(brown, red);
		for (int i = 0; i < answer.size(); i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}
