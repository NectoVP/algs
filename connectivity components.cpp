#include <iostream>
#include <vector>
#include <set>

typedef std::vector<std::pair <std::pair<int, int>, std::vector<int>>> my_graph;

// 0 - белый, 1 - серый, 2 - черный
// 1 - цвет, 2 - компонента

void input(int n, int m, my_graph& graph, std::set<int>& trap) {
    int ind, temp;
    for (int i = 0; i < m; ++i) {
        std::cin >> ind >> temp;
        graph[ind].second.push_back(temp);
        graph[temp].second.push_back(ind);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        if (temp == 1)
            trap.insert(i + 1);
    }
}

void visit(my_graph& graph, int ind, int count, std::set<int>& trap, std::vector<bool>& danger_comp) {
    graph[ind].first.first = 1;
    graph[ind].first.second = count;
    if (trap.find(ind) != trap.end()) {
        danger_comp[count - 1] = false;
    }
    for (int i = 0; i < graph[ind].second.size(); ++i) {
        if (graph[graph[ind].second[i]].first.first == 0)
            visit(graph, graph[ind].second[i], count, trap, danger_comp);
    }
    graph[ind].first.first = 2;
}

void dfs(my_graph& graph, std::set<int>& trap, std::vector<bool>& danger_comp) {
    for (auto i : graph)
        i.first.first = 0;
    int count = 1;

    for (int i = 1; i < graph.size(); ++i) {
        if (graph[i].first.first == 0) {
            danger_comp.push_back(true);
            visit(graph, i, count, trap, danger_comp);
            ++count;
        }
    }
    std::cout << count - 1 << std::endl;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    my_graph graph(n + 1);
    std::set <int> trap;
    std::vector<bool> danger_comp;
    input(n, m, graph, trap);
    dfs(graph, trap, danger_comp);
    for (int i = 1; i < graph.size(); ++i) {
        std::cout << graph[i].first.second << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < danger_comp.size(); ++i)
        std::cout << !(danger_comp[i]) << " ";
    return 0;
}
