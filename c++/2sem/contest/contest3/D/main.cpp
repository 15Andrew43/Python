#include <iostream>
#include <unordered_map>
#include <vector>


class Graph {
private:
    std::unordered_map<int, std::vector<int>> graph_;
public:
    explicit Graph(int N) {
        graph_.reserve(N);
    }
    void NewEdge(int a, int b) {
        graph_[a].push_back(b);
        graph_[b].push_back(a);
    }
    const std::vector<int> getAdjacentVertexes(int a) {
        return graph_[a];
    }
};


int main() {
    int N;
    std::cin >> N;
    Graph graph(N);
    int K;
    std::cin >> K;
    int operation;
    for (int i = 0; i < K; ++i) {
        std::cin >> operation;
        switch (operation) {
            case 1:
                int a, b;
                std::cin >> a >> b;
                graph.NewEdge(a, b);
                break;
            case 2:
                int c;
                std::cin >> c;
                for (int v : graph.getAdjacentVertexes(c)) {
                    std::cout << v << ' ';
                }
                std::cout << '\n';
                break;
        }
    }
    return 0;
}