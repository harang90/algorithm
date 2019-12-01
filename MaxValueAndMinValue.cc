include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	istringstream iss{s};
	string numStr;
	int num;
	vector<int> intVec;
	while (std::getline(iss, numStr)) {
		num = std::stoi(numStr);
		intVec.push_back(num);
	}
	int max = *std::max_element(intVec.begin(), intVec.nd());
	return answer;
}	
