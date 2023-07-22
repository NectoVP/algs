#include <iostream>
#include <vector>

bool next_combination(std::vector<int>& a, int n) {
	int k = (int)a.size();
	for (int i = k - 1; i >= 0; --i) {
		if (a[i] < n - k + i + 1) {
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	}
	return false;
}

int main() {
	std::vector<int> vec = { 3,4,8 };
	for (int i = 0; i < 3; ++i) {
		next_combination(vec, 9);
		for (auto i : vec)
			std::cout << i << " ";
		std::cout << std::endl;
	}
}
