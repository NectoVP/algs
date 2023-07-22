#include <iostream>
#include <vector>

typedef std::vector<std::pair <int, std::vector<int>>> my_graph;

// 0 - белый, 1 - серый, 2 - черный

void input(int n, int m, my_graph& graph) {
    int ind, temp;
    for (int i = 0; i < m; ++i) {
        std::cin >> ind >> temp;
        graph[ind].second.push_back(temp);
        graph[temp].second.push_back(ind);
    }
}

void visit(my_graph& graph, int ind, bool& flag, int past) {
    if (flag)
        return;
    graph[ind].first = 1;
    for (int i = 0; i < graph[ind].second.size(); ++i) {
        if (graph[graph[ind].second[i]].first == 0)
            visit(graph, graph[ind].second[i], flag, ind);
        if (graph[graph[ind].second[i]].first == 1 && graph[ind].second[i] != past) {
            flag = true;
            return;
        }

    }
    graph[ind].first = 2;
}

void dfs(my_graph& graph) {
    bool flag = false;
    for (auto i : graph)
        i.first = 0;
    for (int i = 1; i < graph.size(); ++i) {
        if (graph[i].first == 0)
            visit(graph, i, flag, 1);
    }
    if (flag)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    my_graph graph(n + 1);
    input(n, m, graph);
    dfs(graph);

    return 0;
}
