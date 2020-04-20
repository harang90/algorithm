#include <iostream>

// 전화번호 목록

// 접두어

#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// if first should come before second return true
bool compare(const string& a, const string& b) {
	auto iterA = a.begin();
	auto iterB = b.begin();
	do {
		if (*iterA > *iterB) return false;
		else if (*iterA < *iterB) return true;
		iterA++;
		iterB++;
		if (iterA == a.end()) return true; 
		if (iterB == b.end()) return false;
	} while (1);
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	
	sort(phone_book.begin(), phone_book.end(), compare);
	for (auto i = phone_book.begin(); i != phone_book.end() - 1; i++) {
		if ((i+1)->substr(0, i->length()).compare(*i) == 0) return false;
	} 
	return true;
}

int main() {
	vector<string> phone_book{"123", "456", "789"};
	cout << solution(phone_book) << "\n";
}
