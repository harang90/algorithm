#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	int eraseNum = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < number.length() - 1; j++) {
			if (number[j] < number[j+1]) {
				number.erase(j,1);
				eraseNum++;
				break;
			}
		}
	}
	for (int i = 0; i < k - eraseNum; i++) {
		number.pop_back();
	}
	return number;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	string number;
	int k;
	for (int i = 0; i < T; i++) {
		cin >> number;
		cin >> k;
		cout << solution(number, k) << std::endl;
	}
}
