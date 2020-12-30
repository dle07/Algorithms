#ifndef GRAPHS_
#define GRAPHS_
#include <vector>
#include <list>
#include <queue> // For BFS
#include <iostream>
using namespace std;


class Graph{

    
    public:
    Graph();
    Graph(vector<vector<int>> adjacencyMatix, vector<list<int>> adjacencyList);
    ~Graph();

    vector<vector<int>> adjMat; // n x n matrix to represent all edges
    vector<list<int>> adjList;

    void bfsMat();
    void dfsMat();

    void bfsList();
    void dfsList();

    void dfsHelper(int vertex,vector<bool> & visited);




};
#endif  