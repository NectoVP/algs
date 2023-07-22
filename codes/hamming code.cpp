#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int get_bits_correcting_amount(int size) {
	int k = 2;
	while (pow(2, k) - 1 < size)
		++k;
	return k;
}

std::string clear_string(std::string& s, std::vector <int>& correct_vec) {
	std::string temp;
	for (int i = 0, j = 0; i < s.size(); ++i) {
		if (j < correct_vec.size()) {
			if (i == correct_vec[j] - 1)
				++j;
			else
				temp += s[i];
		}
		else
			temp += s[i];
	}
	return temp;
}

std::string ham_code(std::string& s) {
	int correct_bits = get_bits_correcting_amount(s.size());
	std::vector <int> correct_vec(correct_bits);

	int fin = 0;

	correct_vec[0] = 1;

	for (int i = 1; i < correct_bits; ++i)
		correct_vec[i] = correct_vec[i - 1] * 2;

	int count = 0;
	bool flag = false;

	for (int i = 0; i < correct_bits; ++i) {
		int p = correct_vec[i];
		fin = 0;
		while (p - 1< s.size()) {
			for (int j = p - 1, k = 0; k < correct_vec[i] && j < s.size(); ++j, ++k) {
				fin += s[j] - '0';
			}
			p += 2 * correct_vec[i];
		}
		if (correct_vec[i] - 1 < s.size())
			fin -= (s[correct_vec[i] - 1] - '0');

		if (correct_vec[i] - 1 < s.size()) {
			if (fin % 2 != ((int)(s[correct_vec[i] - 1] - '0'))) {
				count += correct_vec[i];
				flag = true;
			}
		}
	}

	if (flag == true && count >= 1)
		s[count-1] = ((s[count-1] == '1') ? '0' : '1');
	std::string msg = clear_string(s, correct_vec);
	return msg;
}

int main() {
	int k;
	std::cin >> k;
	std::string s;
	while (std::cin >> s)
		std::cout << ham_code(s) << std::endl;

	return 0;
}
