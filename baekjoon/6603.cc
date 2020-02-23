#include <iostream>
#include <vector>

using namespace std;

vector<int> setS;

void selectOne(vector<int> selected, int prev) {
	// 	1-1. 6개를 골랐으면 cout
	if (selected.size() == 6) {
		for(int i = 0; i < 6; i++) {
			cout << selected[i] << " ";
		}
		cout << endl;
		return;
	}
	// 	1-2. for loop을 돌면서 그 다음 큰 수 선택
	for (int i = 0; i < setS.size(); i++) {
		if (setS[i] > prev) {
			selected.push_back(setS[i]);
			selectOne(selected, setS[i]);
			selected.pop_back();
		}
	}	
	//  1-3. 더 이상 숫자를 못 고르면 return
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	while (1) {
		int k;
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			int elem;
			cin >> elem;
			setS.push_back(elem);	
		}

		// 문제 풀이 접근 방식
		// 1. 작은 수부터 1개 선택하고 고른 선택 수 +1, 선택한 수 고를 수 있는 수에서 제외

		for (int i = 0; i < setS.size(); i++) {
			vector<int> selected;
			selected.push_back(setS[i]);
			selectOne(selected, setS[i]);
			selected.pop_back();
		}
		cout << endl;
		setS.clear();
	}
	return 0;
}
