// [프로그래머스] 가장 큰 수

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";
	
	vector<pair<int,int>> pair_vec;

	vector<int>::iterator numbers_iter;
	for (numbers_iter = numbers.begin(); numbers_iter != numbers.end(); numbers_iter++) {
		if (*numbers_iter >= 10) {
			if (*numbers_iter >= 100) {
				if (*numbers_iter >= 1000) pair_vec.push_back(make_pair(3, *numbers_iter));
				else pair_vec.push_back(make_pair(2, *numbers_iter * 10 + (*numbers_iter / 100) * 1));
			} else pair_vec.push_back(make_pair(1, *numbers_iter * 100 + (*numbers_iter / 10) * 11));
		} else pair_vec.push_back(make_pair(0, *numbers_iter * 1000 + *numbers_iter * 111)); 
	}

	std::sort(pair_vec.begin(), pair_vec.end(), [](const pair<int,int> & a, pair<int,int> & b) -> bool {
		return a.second > b.second;
	});
	
	vector<pair<int,int>>::iterator pair_vec_iter;
	for (pair_vec_iter = pair_vec.begin(); pair_vec_iter != pair_vec.end(); pair_vec_iter++) {
		int element;
		if (pair_vec_iter->first == 0) element = (pair_vec_iter->second - ((pair_vec_iter->second / 1000) * 111)) / 1000;
		else if (pair_vec_iter->first == 1) element = (pair_vec_iter->second - ((pair_vec_iter->second / 1000) * 11)) / 100;
		else if (pair_vec_iter->first == 2) element = (pair_vec_iter->second - (pair_vec_iter->second / 1000)) / 10;
		else element = pair_vec_iter->second;
		answer.append(to_string(element));
	}
	return answer;
}

int main() {
	vector<int> numbers{4, 45, 446, 5, 9};
	std::cout << solution(numbers) << std::endl;
}
