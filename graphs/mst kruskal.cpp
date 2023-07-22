#include <vector>
#include <iostream>
using namespace std;

struct elem {
    int s;
    int f;
    int w;
};

typedef std::vector<elem> my_graph;

void input(int n, int m, my_graph& graph) {
    int ind, temp, weight;
    for (int i = 0; i < m; ++i) {
        std::cin >> ind >> temp >> weight;
        if(ind != temp)
            graph.push_back(elem{ ind, temp, weight });
    }
}

void qs(int start, int end, my_graph& graph) {
    if (start >= end)
        return;
    int i = start, j = end;
    int x = graph[(start + end) / 2].w;
    while (i <= j) {
        while (graph[i].w < x)
            i++;
        while (graph[j].w > x)
            j--;
        if (i <= j) {
            int temp = graph[i].w;
            graph[i++].w = graph[j].w;
            graph[j--].w = temp;
        }
    }
    qs(start, j, graph);
    qs(i, end, graph);
}

int get(int i, std::vector<int>& p) {
    return p[i] == i ? i : (p[i] = get(p[i], p));
}

void join(int a, int b, std::vector<int>& p, std::vector<int>& rank) {
    a = get(a, p), b = get(b, p);
    if (a == b)
        return;
    if (rank[a] > rank[b])
        std::swap(a, b);
    if (rank[a] == rank[b])
        rank[b]++;
    p[a] = b;
    //rank[a] += rank[b];
}

int kruskal(my_graph& graph, std::vector<int>& p, std::vector<int>& rank) {
    int sum = 0;
    for (auto it = graph.begin(); it != graph.end(); ++it) {    
        if (get((*it).f - 1, p) != get((*it).s - 1, p)) {
            sum+=(*it).w;
            join((*it).f - 1, (*it).s - 1, p, rank);
        }
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, m;
    std::cin >> n >> m;
    my_graph graph;
    input(n, m, graph);
    qs(0, graph.size() - 1, graph);

    std::vector<int> p(n);
    for (int i = 0; i < p.size(); ++i)
        p[i] = i;

    std::vector<int> rank(n, 1);

    std::cout << kruskal(graph, p, rank);

    return 0;
}
