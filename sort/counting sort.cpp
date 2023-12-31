#include <iostream>
#include <vector>
using namespace std;

vector <int> cs(vector <int>& vec, int k) {
    vector <int> c(k + 1);
    vector <int> b(vec.size()+1);
    
    for (int i = 0; i < k + 1; ++i)
        c[i] = 0;

    for (int i = 0; i < vec.size(); ++i)
        c[vec[i]] = c[vec[i]] + 1;
    
    for (int i = 1; i < k + 1; ++i) 
        c[i] += c[i - 1];

    for (int i = vec.size(); i > 0; --i) {
        b[c[vec[i-1]]-1] = vec[i-1];
        c[vec[i-1]]--;
    }
    return b;
}
   
int main() {
    int n, max = 0;
    vector <int> vec;
    cin >> n;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        vec.push_back(a);
        if (vec[i] > max)
            max = vec[i];
    }
    vector <int> vec2 = cs(vec, max);

    for (int i = 0; i < vec2.size()-1; i++)
        cout << vec2[i] << ' ';

    return 0;
}
