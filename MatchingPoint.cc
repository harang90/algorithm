
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int solution(string word, vector<string> pages) {
	int answer = 0;
	int pageNum = pages.size();
	vector<string> pageNames;
	vector<float> matchingScores;
	vector<int> linkScores;
	vector<int> stdScores;
	vector<int> linkNums;
	vector<float> linkScoresToOther;
	vector<vector<string>> linkedPagesList;

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
							if ((wordRead[pos-1] >= 'a') && (wordRead[pos-1] <= 'z')) {
								continue;
							}
						}
						if ((wordRead.length() -1) >= (pos + word.length())) {
							if((wordRead[pos+word.length()] >= 'a') && (wordRead[pos+word.length()] <= 'z')) {
								continue;
							}
						}
					}
					stdScore++;
				}
			}
		}
		linkedPagesList.push_back(linkedPages);
		linkScoresToOther.push_back(static_cast<float>(stdScore) / static_cast<float>(linkedPages.size()));
		linkNums.push_back(linkedPages.size());
		stdScores.push_back(stdScore);
	}	
//	for (int i = 0; i < stdScores.size(); i++) {
//		std::cout << i << " PAGE의 기본 점수: " << stdScores[i] << ". " << i << "의 외부 링크 수: "<< linkNums[i] << std::endl;
//		std::cout << i << " PAGE의 다른 이에게 점수: " << linkScoresToOther[i] << std::endl;
//	}
	for (int i = 0; i < pages.size(); i++) {
		float finalScore{0};	
		finalScore += stdScores[i];
		for (int j = 0; j < pages.size(); j++) {
			if (j != i) {
				if (std::find(linkedPagesList[j].begin(), linkedPagesList[j].end(), pageNames[i]) != linkedPagesList[j].end()) finalScore += linkScoresToOther[j];
			}
		}
		matchingScores.push_back(finalScore);
	}
//	for (int i = 0; i < pages.size(); i++) {
//		std::cout << i << " PAGE의 매칭 점수: " << matchingScores[i] << std::endl;
//	}
	answer = std::distance(matchingScores.begin(), std::max_element(matchingScores.begin(), matchingScores.end()));
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
