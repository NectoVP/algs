#include <iostream>
#include <vector>
#include <string>
#include <cmath>

typedef std::vector<std::vector<int>> my_graph;

void input(int n, int m, my_graph& graph) {
    int first, second, weight;

    for (int i = 0; i < m; ++i) {
        //scanf("%d %d %d", &first, &second, &weight);
        std::cin >> first >> second >> weight;
        graph[first - 1][second - 1] = weight;
    }
}

void floyd(my_graph& graph, int condition) {
    int size = graph.size();
    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (std::abs(j - k) <= condition && std::abs(i - k) <= condition)
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m, condition;
    std::cin >> n >> m >> condition;
    my_graph graph(n, std::vector<int>(n, 1000000));
    input(n, m, graph);

    floyd(graph, condition);

    //scanf("%d", &m);
    std::cin >> m;
    int start, finish;
    for (int i = 0; i < m; ++i) {
        //scanf("%d %d", &start, &finish);
        std::cin >> start >> finish;
        std::cout << (graph[start - 1][finish - 1] >= 1000000 ? -1 : graph[start - 1][finish - 1]) << '\n';
        //printf("%d\n", (graph[start - 1][finish - 1] >= 1000000 ? -1 : graph[start - 1][finish - 1]));
    }

    return 0;
}
