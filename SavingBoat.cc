// [프로그래머스] 구명 보트

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
  std::sort(people.begin(), people.end());
	while (!people.empty()) {
		if((people[0] + people.back() <= limit) && (people.size() != 1)) people.erase(people.begin());
		people.pop_back();
		answer++;
	}
	return answer;
}

int main() {
	int T, test_case;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		int peopleNum;
		cin >> peopleNum;
		vector<int> people;
		for (int i = 0; i < peopleNum; i++) {
			int weight;
			cin >> weight;
			people.push_back(weight);
		}
		int limit;
		cin >> limit;
		cout << solution(people, limit) << std::endl;
	}
}
