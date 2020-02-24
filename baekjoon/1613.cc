#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[6][12];
char map[6][12];

vector<pair<int,int>>& findNeighbor(vector<pair<int,int>>& pairs, int i, int j) {
	visited[i][j] = true;
	pair<int,int> elem = make_pair(i,j);
	pairs.push_back(elem);
	char color = map[i][j];
	//up
	if ( (i-1) >= 0) {
		if (map[i-1][j] == color && visited[i-1][j] == 0) {
			pairs = findNeighbor(pairs, i-1, j);
		}
	} 
	//right
	if ( (j+1) < 12) {
		if (map[i][j+1] == color && visited[i][j+1] == 0) {
			pairs = findNeighbor(pairs, i, j+1);
		}
	}
	//down
	if ( (i+1) < 6) {
		if (map[i+1][j] == color && visited[i+1][j] == 0) {
			pairs = findNeighbor(pairs, i+1, j);
		}
	}
	//left
	if ( (j-1) >= 0) {
		if (map[i][j-1] == color && visited[i][j-1] == 0) {
			pairs = findNeighbor(pairs, i, j-1);
		}
	}
	return pairs;
}

int main() {
	freopen("input.txt", "r", stdin);
	for(int i = 0; i < 12; i++) {
		string input;
		cin >> input;
 		for (int j = 0; j < 6; j++) {
			map[5-j][i] = input[j];
			visited[j][i] = false;
		}
	}
	int ans{0};	
	while (1) {
		bool connected = false;
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 12; i++) {
				if (visited[j][i] == false && map[j][i] != '.') {
					vector<pair<int, int>> connectedPairs;
					connectedPairs = findNeighbor(connectedPairs, j, i);
					if (connectedPairs.size() >= 4) {
						if (!connected) connected = true;
						for (auto iter = connectedPairs.begin(); iter != connectedPairs.end(); iter++) {
							map[iter->first][iter->second] = '.';
						}
					}
				}
			}
		}
		if (connected) ans++;
		else break;
		//cout << "BEFORE ==========================" << endl;
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 12; i++) {
				//cout << map[j][i];
			}
			//cout << endl;
		}
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 11; i++) {
				if (map[j][i+1] == '.') {
					memcpy(&map[j][1], &map[j][0], i+1);
					map[j][0] = '.';
				}
			}
		}
		//cout << "AFTER ==========================" << endl;
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 12; i++) {
				//cout << map[j][i];
				visited[j][i] = 0;
			}
			//cout << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
