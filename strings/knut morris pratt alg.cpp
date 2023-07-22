#include <iostream>
#include <vector>
#include <string>

void build_pi(std::string& s1, std::string& s2, std::vector<int>& pi) {
    int i = 1, j = 0;
    while (i < s1.size()) {
        if (s1[i] == s2[j]) {
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

void kmp(std::string& s1, std::string& s2) {
    std::vector<int> answer;
    std::vector<int> pi(s1.size() + 1);
    pi[1] = 0;
    build_pi(s1, s2, pi);
    int i = 0, j = 0;
    int n = s1.size(), m = s2.size();
    while (i < n && j < m) {
        if (s1[i] == s2[j]) {
            ++i;
            ++j;
        }
        else {
            if (j > 0)
                j = pi[j];
            else
                ++i;
        }
        if (j == m) {
            answer.push_back(i - m);
            j = 0;
        }
    }

    std::cout << answer.size() << std::endl;
    for (auto i : answer)
        std::cout << i << " ";

}

int main() {
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    if (s2.length() > s1.length())
        std::swap(s1, s2);

    kmp(s1, s2);

    return 0;
}
