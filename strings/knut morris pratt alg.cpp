#include <iostream>
#include <vector>
#include <string>

void build_pi(const std::string& pattern, std::vector<int>& pi) {
    int m = pattern.size();
    int j = 0;
    pi[0] = 0;

    for (int i = 1; i < m; i++) {
        if (pattern[i] == pattern[j]) {
            j++;
        }
        else {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = pi[j - 1];
            }
        }
        pi[i] = j;
    }
}

void kmp(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> pi(m, 0);

    build_pi(pattern, pi);

    std::vector<int> occurrences;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            occurrences.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }

    std::cout << occurrences.size() << std::endl;
    for (auto index : occurrences) {
        std::cout << index << " ";
    }
}

int main() {
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    if (s2.length() > s1.length()) {
        std::swap(s1, s2);
    }

    kmp(s1, s2);

    return 0;
}
