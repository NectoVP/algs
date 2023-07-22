#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <set>

typedef std::vector<std::vector<int>> my_graph;

void input(int n, int m, my_graph& graph, std::set<int>& marked) {
    int k, first, second;
    std::cin >> k;

    for (int i = 0; i < k; ++i) {
        std::cin >> first >> second;
        marked.insert((first - 1) * m + (second - 1));
    }

    int j = -1;
    for (int i = 0; i < n * m; ++i) {
        if (i % m == 0) {
            j += 1;
        }

        if (marked.find(i) != marked.end())
            continue;

        if (i % m != 0 && marked.find(i - 1) == marked.end())
            graph[i].push_back(i - 1);
        if (i % m != (m - 1) && marked.find(i + 1) == marked.end())
            graph[i].push_back(i + 1);
        if (j != 0 && marked.find(i - m) == marked.end())
            graph[i].push_back(i - m);
        if (j != n - 1 && marked.find(i + m) == marked.end())
            graph[i].push_back(i + m);

    }

}

bool dfs(my_graph& graph, std::vector<bool>& used, int v, std::vector<int>& match) {
    if (used[v])
        return false;
    used[v] = true;

    for (int i = 0; i < graph[v].size(); ++i) {
        if (match[graph[v][i]] == -1 || dfs(graph, used, match[graph[v][i]], match)) {
            match[graph[v][i]] = v;
            return true;
        }
    }
    return false;
}


int main()
{
    int n, m, start, end;
    std::cin >> n >> m;
    std::set<int> marked;
    my_graph graph(n*m);
    input(n, m, graph, marked);

    std::vector<bool> used(graph.size(), false);
    std::vector<int> match(graph.size(), -1);

    int count = 0;

        for (int i = 0; i < graph.size(); ++i) {
        
        if (marked.find(i) != marked.end())
            continue;

        std::fill(used.begin(), used.end(), false);
        dfs(graph, used, i, match);
            
    }
    
    for (int i = 0; i < match.size(); ++i) {
        if (match[i] != -1)
            ++count;
    }
    
    std::cout << count;

    return 0;
}
