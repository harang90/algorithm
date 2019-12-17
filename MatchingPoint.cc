
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int solution(string word, vector<string> pages) {
	int answer = 0;
	int pageNum = pages.size();
	vector<string> pageNames;
	vector<int> matchingScores;
	vector<int> linkScores;
	vector<int> stdScores;
	vector<int> linkNum;

	for (int i = 0; i < pages.size(); i++) {

		stringstream ss;
		ss.str(pages[i]);

		//parse head
		while (!ss.eof()) {
			std::string word;
			ss >> word;

			if (word.find("content=\"") != std::string::npos) {
				// TODO. pos_1 \" 만으로 되는지 확인 필요
				int pos_1 = word.find("\"");
				int pos_2 = word.find("\">");
				word = word.substr(strlen("content=\""), pos_2 - pos_1);
				pageNames.push_back(word);
				break;
			}
		}

		//parse body
		while (!ss.eof()) {
			std::string word;
			ss >> word;

			//process links
			if (word.find("href=\"") != std::string::npos) {
			}
		}
		std::vector<string> links;

		//pageNames.push_back();
		//scores.push_back();
	}	
	//answer = min_element();
	return answer;
}

int main() {
	string word{"blind"};	
	vector<string> pages{
		"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", 
		"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>",
		"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"};
	std::cout << solution(word, pages) << std::endl;
}
