#include <iostream>
#include <climits>

int solution (int n) {
	int last2, last1, num;
	last2 = 0;
	last1 = 1;
	for (int i = 2; i <= n; i++) {
		num = last1 % 1234567 + last2 % 1234567;
		last2 = last1;
		last1 = num;
	}
	return num % 1234567;
}

int main() {
	int n;
	n = 100000;
	std::cout << solution (n) << std::endl;
}
