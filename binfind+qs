#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void qs(int start, int end, vector<int> &vec) {
    if(start >= end)
    return;
    int i = start, j = end;
    int x = vec[(start+end) / 2];
    while(i <= j) {
        while(vec[i] < x)
        i++;
        while(vec[j] > x)
        j--;
        if(i <= j) {
        int temp = vec[i];
        vec[i++] = vec[j];
        vec[j--] = temp;
    }
}
    qs(start, j, vec);
    qs(i, end, vec);
}
int bin (int start, int end, int num) {
    int mid = v[(start+end) / 2];
    if(start > end)
    return -1;
        if(num == mid)
    return (start+end) / 2;
    if(num > mid) {
    start = (start+end) / 2 + 1;
        bin(start, end, num);
}
   else {
        end = (start+end) / 2 - 1;
    bin(start, end, num);
}
}
int main () {
    srand(time(0)); 
    int n;
	vector <int> v;
    cin >> n;
        for(int i = 0; i < n; ++i)
        v.push_back(rand() % 100 +1);
        qs(0, n-1, v);
        for(int i = 0; i < n; i++)
    cout << v[i] << ' ';
    cout << '\n';
    int num;
    cin >> num;
        int find = -1;
        find = bin(0, n-1, num);
    cout << find;
    return 0;
}
