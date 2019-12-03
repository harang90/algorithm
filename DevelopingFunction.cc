#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int size = progresses.size();
	int score;
	int cur = 0;
	while (cur < size) {
		while (progresses[cur] < 100) {
			for (int i = cur; i < size; i++) {
				progresses[i] += speeds[i];
			}
		}
		score = 0;
		for (int i = cur; i < size; i++) {
			if (progresses[i] >= 100) {
				score++;
				cur++;
			} else {
				break;
			}
		}
		answer.push_back(score);
	}	
	return answer;
}

int main() {
	vector<int> progresses{};
	vector<int> speeds{};
	vector<int> answer = solution(progresses, speeds);
	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
}
