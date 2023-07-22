#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector <int> vec;
    for(int i = 0, a; i < n;++i){
        cin >> a;
        vec.push_back(a);
    }
    for(int i = 1; i < n; ++i) {
        int key = vec[i];
        for(int j = i-1; j >= 0; --j) {
        if(key > vec[j])
        break;
        swap(vec[j], vec[j+1]);
        }
    }
    for(auto const &i : vec) {
        cout << i << " ";
    }
    return 0;
}
