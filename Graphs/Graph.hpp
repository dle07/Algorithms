#ifndef GRAPHS_
#define GRAPHS_
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <queue> // For BFS
#include <iostream>

#include "./../Classes-HelperMethods/AdjacencyList.cpp"
using namespace std;




class Graph{

    
    public:

    Graph();
    Graph(int n);
    Graph(vector<vector<int>> adjacencyMatix, int n);
    ~Graph();

    vector<int> parent; //Two purposes, allows us to backtrack a path from the end node to start node and allows us to keep track of nodes visited
    vector<int> level;  //Amount of steps taken to go to a particular vertex from given starting vertex
    vector<vector<int>> adjMat; // n x n matrix to represent all edges
    vector<list<int>> adjList;

    void bfsMat();
    void dfsMat();

    void bfsList(int startVertex);
    void dfsList();

    void dfsHelper(int vertex,vector<bool> & visited);

    string reconstructPath( int end);

    void reset();




};
#endif  