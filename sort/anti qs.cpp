#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector <int> vec;
    for(int i = 1, a; i <= n;++i) {
        vec.push_back(i);
    }
    for(int i = 2; i < n; ++i) {
    swap(vec[i], vec[i / 2]);
   }
   for(auto const &i : vec)
    cout << i << " ";

    return 0;
}
