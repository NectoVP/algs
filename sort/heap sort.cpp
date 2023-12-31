#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &vec, int i, int size) {
    int l = i * 2 + 1, r = i * 2 + 2, k = i;
    if (l < size && vec[l] > vec[k])
        k = l;
    if (r < size && vec[r] > vec[k])
        k = r;
    if (k != i) {
        swap(vec[i], vec[k]);
        heapify(vec, k, size);
    }
}

void build_heap(vector <int>& vec) {
    for (int i = vec.size() / 2; i >= 0; --i)
        heapify(vec, i, vec.size());
}

void hs(vector <int> &vec) {
    build_heap(vec);
    int size = vec.size();
    for (int i = 0; i < vec.size(); ++i) {
        swap(vec[0], vec[vec.size() - 1 - i]);
        size--;
        heapify(vec, 0, size);
    }
}

int main() {
    vector <int> vec;
    int n;
    cin >> n;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        vec.push_back(a);
    }
    hs(vec);
    for (auto i : vec)
        cout << i << " ";

    return 0;
}
