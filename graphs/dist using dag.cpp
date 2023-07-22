#include <iostream>
#include <vector>
#include <queue>
#include <deque>

typedef std::vector<std::pair<int, std::vector<int>>> my_graph;

void input(int n, int m, my_graph& graph, std::vector<int>& deg) {
    int first, second, weight;

    for (int i = 0; i < m; ++i) {
        std::cin >> first >> second >> weight;
        graph[first - 1].second[second - 1] = weight;
        deg[second - 1]++;
    }

    /*for (int i = 0; i < n; ++i) {
        if(graph[i].second[i] == INT_MAX)
        graph[i].second[i] = 0;
    }*/
}

void bfs(my_graph& graph, std::vector<int>& deg, std::deque<int>& deq) {
    std::queue<int> q;
    for (int i = 0; i < graph.size(); ++i) {
        if (deg[i] == 0) {
            q.push(i);
            deq.push_back(i);
        }
    }
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[temp].second[i] == INT_MAX)
                continue;
            deg[i]--;
            if (deg[i] == 0) {
                q.push(i);
                deq.push_back(i);
            }
        }
    }
}


void dag(my_graph& graph, std::deque<int>& deq, int start, int fin) {
    std::vector <int> d(graph.size(), INT_MAX);
    d[start] = 0;
    int cur = -1;
    while (cur != start) {
        cur = deq.front();
        deq.pop_front();
    }
    int ind = start;
    while (!deq.empty()) {
        for (auto it = deq.begin(); it != deq.end(); ++it) {
            if (d[(*it)] > d[ind] + graph[ind].second[(*it)] && d[ind] != INT_MAX && graph[ind].second[(*it)] < INT_MAX)
                d[(*it)] = d[ind] + graph[ind].second[(*it)];
        }
        ind = deq.front();
        deq.pop_front();
    }
    std::cout << (d[fin] == INT_MAX ? -1 : d[fin]);
}

int main()
{
    int n, m, s, t;
    std::cin >> n >> m;
    std::cin >> s >> t;
    std::deque<int> deq;
    std::vector<int> deg(n, 0);
    my_graph graph(n, std::make_pair<int, std::vector<int>>(0, std::vector<int>(n, INT_MAX)));
    input(n, m, graph, deg);
    bfs(graph, deg, deq);

    dag(graph, deq, s - 1, t - 1);
    return 0;
}
