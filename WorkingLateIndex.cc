#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
	std::sort(works.begin(), works.end(), greater<int>());
	vector<int>::iterator iter = works.begin();
	while (n > 0) {
		if ((iter+1 == works.end()) && (*iter > 0)) {
			*iter -= 1;
			n--;
			iter = works.begin();
		} else if (*iter >= (*(iter+1)) && (*iter > 0)) {
			*iter -= 1;
			n--;
			iter = works.begin();
		} else if ((*iter == 0) && (iter + 1 == works.end())) {
			break;
		} else {
			iter++;
		}
	}
	long long answer = 0;
	for (iter = works.begin(); iter != works.end(); iter++) {
		answer += ((*iter) * (*iter));
	}
	return answer;
}

int main() {
	int n = n;
	vector<int> works{4,3,3};
	cout << solution(n, works) << endl;
}
