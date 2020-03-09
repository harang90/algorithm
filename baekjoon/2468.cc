#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int** height;
bool** visited;
int N;
int rain;

bool checkForTarget(int X, int Y) {
	if (X < 0 || Y < 0 || X >= N || Y >= N) return false;
	if (visited[X][Y] == false && height[X][Y] > rain) return true;
	return false;
}

int checkNeighbor(int& neighborNum, queue<pair<int,int>> &queue) {
	if (queue.empty()) return neighborNum;
	pair<int, int> elem = queue.front();
	queue.pop();
	neighborNum++;

	if (checkForTarget(elem.first, elem.second-1)) { // up
		queue.push(make_pair(elem.first, elem.second-1));
		visited[elem.first][elem.second-1] = true;
	} 
	if (checkForTarget(elem.first, elem.second+1)) { // down
		queue.push(make_pair(elem.first, elem.second+1));
		visited[elem.first][elem.second+1] = true;
	} 
	if (checkForTarget(elem.first-1, elem.second)) { // left
		queue.push(make_pair(elem.first-1, elem.second));
		visited[elem.first-1][elem.second] = true;
	} 
	if (checkForTarget(elem.first+1, elem.second)) { // right
		queue.push(make_pair(elem.first+1, elem.second));
		visited[elem.first+1][elem.second] = true;
	} 
	return checkNeighbor(neighborNum, queue);
}

void reset() {
	for (int i = 0; i < N; i++) {
		delete[] visited[i];
		visited[i] = new bool[N]();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> N;
	visited = new bool*[N];
	height = new int*[N];
	for (int i = 0; i < N; i++) {
		height[i] = new int[N];	
		visited[i] = new bool[N]();
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
		}
	}
	int max = -1;
	for (rain = 0; rain <= 100; rain++) {
		int num = 0;
		queue<pair<int,int>> queue;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == false && height[i][j] > rain) {
					int neighborNum = 0;
					queue.push(make_pair(i,j));
					visited[i][j] = true;
					checkNeighbor(neighborNum, queue);
					num++;
				}
			}
		}
		//printf("rain height = %d, num = %d\n", rain, num);
		if (num > max) max = num;
		if (num == 0) break;
		//nums.push_back(num);
		reset();
	}
	//for (int i = 0; i < nums.size(); i++) {
		//cout << nums[i] << " ";	
	//}
	//cout << endl;
	printf("%d\n", max);
}
