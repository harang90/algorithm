
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(string word, vector<string> pages) {
	int answer = 0;
	int pageNum = pages.size();
	vector<string> pageNames;
	vector<int> matchingScores;
	vector<int> linkScores;
	vector<int> stdScores;
	vector<int> linkNums;

	// 1. word to lower
	std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });

	for (int i = 0; i < pages.size(); i++) {

		stringstream ss;
		std::string wordRead;
		int stdScore{0};

		ss.str(pages[i]);
		//parse head
		while (!ss.eof()) {
			ss >> wordRead;
			if (wordRead.find("content=\"") != std::string::npos) {
				// TODO. pos_1 \" 만으로 되는지 확인 필요
				int pos_1 = wordRead.find("\"");
				int pos_2 = wordRead.find("\"/>");
				wordRead = wordRead.substr(strlen("content=\""), pos_2 - 1 - pos_1);
				pageNames.push_back(wordRead);
				break;
			}
		}

		//parse body
		vector<string> linkedPages;
		while (!ss.eof()) {
			ss >> wordRead;

			//process links
			if (wordRead.find("href=\"") != std::string::npos) {
				int pos_1 = wordRead.find("\"");
				int pos_2 = wordRead.find("\">");
				wordRead = wordRead.substr(strlen("href=\""), pos_2 - 1 - pos_1);
//				if (std::find(linkedPages.begin(), linkedPages.end(), word) == linkedPages.end()) linkedPages.push_back(word);
				linkedPages.push_back(wordRead);
			} else {
				// wordRead to lower	
				// find
				// find if valid
				// stdScore++;
				std::transform(wordRead.begin(), wordRead.end(), wordRead.begin(), [](unsigned char c){ return std::tolower(c); });
				std::size_t pos = wordRead.find(word);
				if (pos != std::string::npos) {
					if (wordRead.length() != word.length()) {
						if ((pos -1) >= 0) {
							if ((wordRead[pos-1]] >= 'a') && (wordRead[pos-1] <= 'z')) {
								continue;
							}
						}
						if ((wordRead.length() -1) >= (pos + word.length())) {
							if((wordRead[pos+word.length()] >= 'a') && (wordRead[pos+word.length] <= 'z')) {
								continue;
							}
						}
					}
					stdScore++;
				}
			}
		}
		linkNums.push_back(linkedPages.size());
		stdScores.push_back(stdScore);
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
