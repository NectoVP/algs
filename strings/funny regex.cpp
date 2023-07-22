#include <iostream>
#include <unordered_map>
#include <vector>
#include <regex>
#include <string>

int main() {    
    int n;
    std::cin >> n;

    std::string origin;
    std::getline(std::cin, origin);
    
    std::regex reg("(([A-Z][a-z]+[ ]){3}[0-9]{2}[ ]([+]?[0-9][(]?[0-9]{3}[)]?[-]?[0-9]{3}[-]?[0-9]{2}[-]?[0-9]{2})[ ]g[\.][A-Z]{3}[,][ ]ul[\.][A-Z][a-z]+[,][ ]d[\.]([0-9])*)");
    std::smatch match;
    
    for (int i = 0; i < n; ++i) {
        
        std::getline(std::cin, origin);
        std::string s = origin;

        if (std::regex_search(s, match, reg) == false) {
            std::cout << "NO\n";
            continue;
        }

        while (std::regex_search(s, match, reg)) {
            s = match.str(1);
            if (s.size() != origin.size()) {
                std::cout << "NO\n";
                break;
            }
            else {
                std::cout << "YES\n";
                break;
            }
        }
    }


    return 0;
}



//examples
1
Bak Ve Qd 67 +84717214117 g.MWN, ul.Mhowfwnyepb, d.87 -> NO
1
Ew Ob Ad 47 71778163784 g.SRB, ul.Uzmeuxmxm, d.618 -> YES
