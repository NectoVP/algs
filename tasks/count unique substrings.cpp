#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct elem {
    std::string s;
    int count;
};

struct comp {
    bool operator()(const elem& a, const elem& b) const {
        return a.s < b.s;
    }
};

std::vector<int> buildlcp(const std::string& s, const std::vector<int>& sa) {
    int n = s.size();
    std::vector<int> lcp(n);
    std::vector<int> pos(n);

    for (int i = 0; i < n; ++i)
        pos[sa[i]] = i;

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (pos[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[pos[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            ++k;
        lcp[pos[i]] = k;
        if (k > 0)
            --k;
    }

    return lcp;
}

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::vector<elem> vec;
    for (int i = 0; i < s.size(); ++i) {
        std::string suffix = s.substr(i);
        vec.push_back({ suffix, i });
    }

    std::sort(vec.begin(), vec.end(), comp());

    std::vector<int> sa(vec.size());
    for (int i = 0; i < vec.size(); ++i)
        sa[i] = vec[i].count;

    std::vector<int> lcp = buildlcp(s, sa);

    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        count += n - sa[i] - lcp[i - 1];
    }

    std::cout << count << std::endl;

    return 0;
}
