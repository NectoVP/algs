#include <iostream>
#include <vector>

struct elem {
    int f;
    int s;
    int w;
};

typedef std::vector<elem> my_graph;

void input(int n, int m, my_graph& graph) {
    int first, second, weight;

    for (int i = 0; i < m; ++i) {
        std::cin >> first >> second >> weight;
        graph.emplace_back(std::move(elem{ first - 1, second - 1, weight }));
    }

    /*for (int i = 0; i < n; ++i) {
        if(graph[i].second[i] == INT_MAX)
        graph[i].second[i] = 0;
    }*/
}

bool bf(my_graph& graph, int n) {
    std::vector<int> dist(n, INT_MAX);
    dist[graph[0].f] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool flag = true;
        for (int j = 0; j < graph.size(); ++j) {
            if (dist[graph[j].f] != INT_MAX && dist[graph[j].f] + graph[j].w < dist[graph[j].s]) {
                dist[graph[j].s] = dist[graph[j].f] + graph[j].w;
                flag = false;
            }
        }
        if (flag)
            break;
    }
    for (int j = 0; j < graph.size(); ++j) {
        if (dist[graph[j].s] > dist[graph[j].f] + graph[j].w)
            return false;
    }
    return true;
}

int main()
{
    int N, k;
    std::cin >> N >> k;
    
    for (int i = 0; i < N; ++i) {
        int n, m;
        std::cin >> n >> m;
        my_graph graph;
        input(n, m, graph);
        if (bf(graph, n))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    
    return 0;
}
