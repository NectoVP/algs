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

void dfs(my_graph& graph, int ind, int count, int &prev) {
    ++count;
    graph[ind].first = 1;
    prev = ind;
    for (int i = 0; i < graph[ind].second.size(); ++i) {
        if (graph[graph[ind].second[i]].first == 0) {
            
            if (count == graph.size() - 2) {
                std::cout << "YES";
                exit(0);
            }

            dfs(graph, graph[ind].second[i], count, prev);
        }
    }
    //return count;
}

int main()
{
    int n, m;
    int prev = 1, temp = 1;
    std::cin >> n >> m;
    my_graph graph(n + 1);
    input(n, m, graph);

    for (auto& i : graph)
        i.first = 0;
    dfs(graph, 1, 0, prev);
    
    for (auto& i : graph)
        i.first = 0;
    dfs(graph, prev, 0, temp);
    
    //std::cout << dfs(graph, 1, 0);
    std::cout << "NO";
    //std::cout << (count == n ? "YES" : "NO");
    return 0;
}
