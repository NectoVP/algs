#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <queue>

// 0 - белый, 1 - серый, 2 - черный

typedef std::vector<std::pair <int, std::vector<int>>> my_graph;

void input(int n, int m, my_graph& graph, std::vector<int>& deg) {
    int second, first;
    for (int i = 0; i < m; ++i) {
        std::cin >> first >> second;
        graph[first].second.push_back(second);
        deg[second]++;
    }
}

void bfs(my_graph& graph, std::vector<int>& deg) {
    std::queue<int> q;
    int count = 1;
    for (int i = 1; i < graph.size(); ++i) {
        if (deg[i] == 0) {
            q.push(i);
            graph[i].first = count++;
        }
    }
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i : graph[temp].second) {
            deg[i]--;
            if (deg[i] == 0) {
                q.push(i);
                graph[i].first = count++;            }
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    my_graph graph(n + 1);
    std::vector<int> deg(n + 1, 0);
    input(n, m, graph, deg);
    bfs(graph, deg);
    for (int i = 1; i < graph.size(); ++i)
        std::cout << graph[i].first << " ";
    
    return 0;
}
