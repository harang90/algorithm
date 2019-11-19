#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = 0;
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
  vector<int>::iterator lost_iter, res_iter;
  lost_iter = lost.begin();
  res_iter = reserve.begin();
  while ((lost_iter != lost.end()) && (res_iter != reserve.end())) {
    if (*lost_iter < *res_iter) {
      lost_iter++;
    } else {
      if (*lost_iter == *res_iter) {
        lost.erase(lost_iter);
        reserve.erase(res_iter);
      } else res_iter++;
    }
  }
  lost_iter = lost.begin();
  res_iter = reserve.begin();
  while ((lost_iter != lost.end()) && (res_iter != reserve.end())) {
    if (*lost_iter + 1 <  *res_iter) {
      lost_iter++;
    } else {
      if ((*lost_iter - 1 == *res_iter) || (*lost_iter + 1 == *res_iter)) {
        lost.erase(lost_iter);
        reserve.erase(res_iter);
      } else res_iter++;
    }
  }
  return n - lost.size();
}
