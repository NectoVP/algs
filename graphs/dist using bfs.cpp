#include <iostream>
#include <vector>
#include <deque>

typedef std::vector<std::pair <int, std::vector<int>>> my_graph;
// 0 - белый, 1 - серый, 2 - черный

void input(int n, int m, my_graph& graph) {
    int second, first;
    for (int i = 0; i < m; ++i) {
        std::cin >> first >> second;
        graph[first].second.push_back(second);
        graph[second].second.push_back(first);
    }
}

int bfs(my_graph& graph, int start, int end) {
    std::vector<int> dist;
    for (int i = 0; i < graph.size(); ++i)
        dist.push_back(INT_MAX);
    dist[start] = 0;

    std::deque<int>adjacency;
    adjacency.push_back(start);
    while (!adjacency.empty()) {
        int v = adjacency.front();
        adjacency.pop_front();

        for (int j = 0; j < graph[v].second.size(); ++j) {
            if (dist[graph[v].second[j]] == INT_MAX) {
                dist[graph[v].second[j]] = dist[v] + 1;
                adjacency.push_back(graph[v].second[j]);
            }
        }
    }

    if (dist[end] == INT_MAX)
        return -1;
    return dist[end];
}

int main()
{
    int n, m, start, end;
    std::cin >> n >> m;
    my_graph graph(n + 1);
    input(n, m, graph);
    std::cin >> start >> end;

    std::cout << bfs(graph, start, end);
    return 0;
}
