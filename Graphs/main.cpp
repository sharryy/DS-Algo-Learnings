#include <iostream>
#include <set>
#include "vector"
#include "map"

using namespace std;

//Adjacency List
struct Vertex {
    Vertex(int vertexNumber, const set<int> &adjacents) : vertex_number(vertexNumber), adjacents(adjacents) {}

    int vertex_number;
    set<int> adjacents;
};
// --End of Adjacency List


class Graph {
    //For Adjacency List
    vector<Vertex> adj_vector;
public:
    explicit Graph(const vector<Vertex> &v) : adj_vector(v) {}
    //--End of Adjacency List

    explicit Graph(const map<int, set<int, int>> &vertices) : vertices(
            vertices) {} //Constructor for Adjacency List Using Map and Set

    explicit Graph(const vector<vector<int>> &adjacencyMatrix) :
            adjacency_matrix(adjacencyMatrix) {} //For Adjacency Matrix


    Graph(const vector<int> &v, const vector<pair<int, int>> &e) : v_(v), e_(e) {}

    vector<int> v_;
    vector<pair<int, int>> e_;

    bool isEulerWalkable();

    //adjacency List Using Map and Set
    map<int, set<int, int>> vertices;

    //adjacency Matrix
    vector<vector<int>> adjacency_matrix;
};

bool Graph::isEulerWalkable() {
    vector<int> degrees(v_.size());

    for (auto e : e_) {
        degrees[e.first]++;
        degrees[e.second]++;
    }

    //For  Adjacency List
    vector<int> adj_degree(adj_vector.size());

    for (const auto &v: adj_vector) {
        adj_degree[v.vertex_number] = v.adjacents.size();
    }
    //--End of Adjacency List


    //Adjacency Matrix Implementation
    vector<int> degree_matrix(adjacency_matrix.size());
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        for (int j = 0; j < adjacency_matrix.size(); ++j) {
            if (adjacency_matrix[i][j] == 1)
                degree_matrix[i]++;
        }
    }

    int countOdds = 0;

    for (auto d:degrees) {
        if (d % 2 == 1) {
            countOdds++;
        }
    }

    return countOdds == 0 || countOdds == 2;
}


int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<pair<int, int>> e = {{0, 1},
                                {1, 2},
                                {2, 3},
                                {3, 0}};

    Graph g(v, e);
    cout << g.isEulerWalkable() << endl;

    //For Adjacency List
    Graph graph({Vertex(0, {1, 2}),
                 Vertex(1, {0, 2, 3, 4}),
                 Vertex(2, {0, 1, 3}),
                 Vertex(3, {1, 2, 4})});
    //--End of Adjacency List

    //For Adjacency List Using Map and Set
    map<int, set<int, int>> vertice{
            {0, {1, 2}},
            {1, {0, 2, 3, 4}},
            {2, {0, 1, 3}},
            {3, {1, 2, 4}}
    };
    Graph graph1(vertice);

    //For Adjacency Matrix Using Map and Set
    vector<vector<int>> adj_matrix = {{0, 1, 1, 0, 1},
                                      {1, 0, 1, 1, 1},
                                      {1, 1, 0, 1, 0},
                                      {0, 1, 1, 0, 1},
                                      {0, 1, 0, 1, 0}};
    Graph graph2(adj_matrix);

    return 0;
}
