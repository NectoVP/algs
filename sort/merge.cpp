#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector <int> &a, int &l, int &m, int& r) {
    int it1 = 0, it2 = 0;
    vector <int> res(r-l);
    while(l + it1 < m && m + it2 < r) {
        if(a[l+it1] < a[m+it2]) {
            res[it1+it2] = a[l+it1];
            ++it1;
        }
        else {
            res[it1+it2] = a[m+it2];
            ++it2;
        }
    }
    while(l + it1 < m) {
        res[it1+it2] = a[l + it1];
        ++it1;
    }
    while(m  + it2 < r) {
        res[it1+it2] = a[m + it2];
        ++it2;
    }
    for(int i = 0; i < it1+it2; ++i)
        a[l+i] = res[i];
}

void ms(vector <int> &a, int &l, int &r) {
    if(l+1 >= r)
        return;
    int m = (l+r)/2;
    ms(a, l, m);
    ms(a, m, r);
    merge(a, l, m, r);
}

int main () {
    int n, s = 0;
    cin >> n;
    vector <int> vec;
    for(int i = 0, a; i < n;++i){
        cin >> a;
        vec.push_back(a);
    }
    ms(vec, s, n);
    for(auto const &i : vec) {
        cout << i << " ";
    }
    return 0;
}
