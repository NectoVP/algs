#include <cstdio>
#include <vector>
#include <iostream>

void post_traverse(std::vector <int> &vec, int min, int max, int &i) {
    if (i >= vec.size() || vec[i] < min || vec[i] > max)
        return;
    int temp = vec[i++];
	post_traverse(vec, min, temp, i);
	post_traverse(vec, temp, max, i);
    std::cout << temp << " ";
}
int main() {
	std::vector <int> vec;
	int n, x, i = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		vec.push_back(x);
	}
	post_traverse(vec, -2000000000, 2000000000, i);
	return 0;
}
