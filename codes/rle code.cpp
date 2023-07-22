#include <iostream>
#include <string>

bool is_num(char c) {
    return c >= '0' && c <= '9';
}

int get_next(std::string& s1, char& fc, int& i) {
    std::string temp = "0";
    fc = s1[i - 1];
    int j;
    for (j = i; j < s1.length() && is_num(s1[j]); ++j) {
        temp += s1[j];
    }
    i = j + 1;
    return stoi(temp);
}

std::string add_one(std::string& s) {
    std::string temp = "";
    for (int i = 0; i < s.length() - 1; ++i) {
        temp += s[i];
        if (!is_num(s[i]) && !is_num(s[i + 1]))
            temp += '1';
    }
    temp += s[s.length() - 1];
    return (is_num(s[s.length() - 1]) == false) ? temp += '1' : temp;
}

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    int count = 0, count2 = 0;
    char fc, sc;
    int total = 0, p = 1, i = 1;

    s1 = add_one(s1);
    s2 = add_one(s2);
    if (n > m)
        swap(s1, s2);

    count = get_next(s1, fc, i);
    count2 = get_next(s2, sc, p);

    for (; i < s1.length() + 2; ) {
        if (count - count2 >= 0) {
            count -= count2;
            if (fc != sc)
                total += count2;

            if (p >= s2.length())
                break;

            count2 = get_next(s2, sc, p);

            if (count == 0)
                count = get_next(s1, fc, i);
        } else {
            if (fc != sc)
                total += count;

            count2 = -(count - count2);
            count = get_next(s1, fc, i);
        }
    }
    std::cout << ((total < k) ? "Yes" : "No");
    return 0;
}
