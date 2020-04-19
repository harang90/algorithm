#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
			
	// 동명이인이 있을 수 있음	
	map<string, int> map;
	for (auto i = participant.begin(); i != participant.end(); i++) {
		if (map.find(*i) == map.end()) map[*i] = 1;
		else map[*i]++;
	}

	for (auto i = completion.begin(); i != completion.end(); i++) {
		if (map[*i] >= 1) map[*i]--;
	}

	for (auto i = map.begin(); i != map.end(); i++) {
		if (i->second >= 1) return i->first;
	}
}

int main() {
	vector<string> participant{"mislav", "stanko", "mislav", "ana"};	
	vector<string> completion{"stanko", "mislav", "ana"};	
	cout << solution(participant, completion) << endl;
}
