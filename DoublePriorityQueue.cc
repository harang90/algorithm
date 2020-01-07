#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer{0, 0};
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	
	// 1. 모두 다 받는다.
	// 2. min은 minHeap에서 max는 maxHeap에서 뺀다
	// 3.	빈큐를 삭제하라면 무시한다
	// 4. min이 maxHeap에 없으면, 또는 max가 minHeap에 없으면 0,0
	
	for (auto iter = operations.begin(); iter != operations.end(); iter++) {	
		char action = iter->at(0);
		int num = stoi(iter->substr(2, std::string::npos));
		if (action == 'I') {
			maxHeap.push(num);
			minHeap.push(num);
		} else {
			if (num == 1) {
				if (!maxHeap.empty())	maxHeap.pop();
			} else {
				if (!minHeap.empty()) minHeap.pop();
			}
		}
	}
	if (minHeap.empty() || maxHeap.empty()) return answer;
	int max = maxHeap.top();
	int min = minHeap.top();
	bool set = false;
	while (!minHeap.empty()) {
		int pop = minHeap.top();
		minHeap.pop();
		if (pop == max) {
			set = true;
			answer[0] = max;
		}
	}
	if (!set) return answer;
	set = false;
	while (!maxHeap.empty()) {
		int pop = maxHeap.top();
		maxHeap.pop();
		if (pop == min) {
			set = true;
			answer[1] = min;
		}
	}
	if (!set) {
		answer[0] = 0;
		return answer;
	}
	return answer;	
}

int main() {
	//vector<string> operations{"I 16","D 1"};	
	vector<string> operations{"I 7","I 5","I -5","D -1"};	
	vector<int> answer{solution(operations)};
	cout << answer[0] << endl;
	cout << answer[1] << endl;
	return EXIT_SUCCESS;
}
