#include <iostream>
#include <vector>
#include <string>

void build_pi(std::string& s1, std::vector<int>& pi) {
    int i = 1, j = 0;
    while (i < s1.size()) {
        if (s1[i] == s1[j]) {
            pi[i + 1] = j + 1;
            ++i, j++;
        }
        else {
            if (j > 0)
                j = pi[j];
            else {
                pi[i + 1] = 0;
                ++i;
            }
        }
    }
}

int main() {
    std::string s1;
    std::getline(std::cin, s1);

    std::vector<int> pi(s1.size() + 1);
    pi[1] = 0;
    build_pi(s1, pi);

    for (int i = 1; i < pi.size(); ++i)
        std::cout << pi[i] << " ";

    return 0;
}
