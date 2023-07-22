#include <iostream>
#include <cmath>
int main(){
    int n;
    std::cin >> n;
    for (int i = 0; i < pow(2, n); ++i) {
        int temp = (i ^ (i >> 1));
        for (int j = n-1; j >= 0; --j) {
            printf("%d", ((temp & (1 << j)) >> j));}
        std::cout << "\n"; }
    return 0; }
