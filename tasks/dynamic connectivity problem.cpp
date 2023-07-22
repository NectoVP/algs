#include <iostream>
#include <vector>
#include <list>
#include <set>
typedef std::vector<std::set<int>> my_graph;

struct elem {
    int f;
    int s;
    char r;
};

void input(int n, int m, my_graph& graph) {
    int ind, temp;
    for (int i = 0; i < m; ++i) {
        std::cin >> ind >> temp;
        graph[ind - 1].insert(temp - 1);
        graph[temp - 1].insert(ind - 1);
    }

}

void visit(my_graph& graph, int ind, int count, std::vector<int>& p, std::vector<int>& rank, int& another_count, std::vector<int>& used) {
    p[ind] = count;
    used[ind] = 1;
    for (auto it = graph[ind].begin(); it != graph[ind].end(); ++it) {
        if (used[*(it)] == 0)
            visit(graph, *(it), count, p, rank, ++another_count, used);
    }
    rank[ind] = another_count;
}

void dfs(my_graph& graph, std::vector<int>& p, std::vector<int>& rank) {
    for (int i = 0; i < p.size(); ++i)
        p[i] = i;
    int another_count = 1;

    std::vector<int> used(p.size(), 0);

    for (int i = 0; i < graph.size(); ++i) {
        if (used[i] == 0) {
            visit(graph, i, i, p, rank, another_count, used);
            another_count = 1;
        }
    }
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

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> p(n);
    std::vector<int> rank(n, 1);

    std::list<elem> deleted;
    {
        my_graph graph(n);
        input(n, m, graph);
        int first, second;
        char request;
        for (int i = 0; i < k; ++i) {
            std::cin >> request >> first >> second;
            if (request == '-') {
                graph[first - 1].erase(second - 1);
                graph[second - 1].erase(first - 1);
            }
            deleted.emplace_back(std::move (elem{ first - 1, second - 1, request }));
        }
        dfs(graph, p, rank);
    }
   
    
    std::list<char> answer;

    
    for(auto it = deleted.rbegin(); it != deleted.rend(); ++it) {
        if ((*it).r == '?') {
            if ((*it).f == (*it).s) {
                answer.push_back('y');
                continue;
            }

            if (get((*it).f, p) == get((*it).s, p))
                answer.push_back('y');
            else
                answer.push_back('n');
        }
        else
            join((*it).f, (*it).s, p, rank);
    }

    for (auto it = answer.rbegin(); it != answer.rend(); ++it)
        std::cout << ((*it) == 'y' ? "YES" : "NO") << '\n';
    return 0;
}

