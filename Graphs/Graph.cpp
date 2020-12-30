#include "Graph.hpp"



Graph :: Graph(){
};

Graph :: Graph(vector<vector<int>> adjacencyMatrix, vector<list<int>> adjacencyList){
    this -> adjMat = adjacencyMatrix;
    this -> adjList = adjacencyList;
}

Graph :: ~Graph(){  
};


/*  BREADTH FIRST SEARCH FOR ADJACENCY MATRIX REPRESENTATION 
    Time Complexity O(n^2) because we have two loops, while loop that loops through all vertices, and for each vertex, we loop through each row

    1) Create a Queue that allows us to traverse the graph in a breadth first manner
    2) Create a array of size n of booleans called visited, where n == |V|,
    the number of vertices to keep track the vertices we've already visited
    3) Pick any vertex, in this case it'll be the first vertex, enqueue it in the queue

    4) While the queue is not empty
        -Dequeue the front vertex, mark that vertex as visited (We're visting it right now)
        -Process the data
        -Explore all edges of that vertex, which means to loop through that vertex's row using a foor loop.
        -Check to see if that vertex hasn't already been visited
        -When you "visit it", lets enqueue it in the queue, and print out it's value
*/
// Our queue represents the node's we've yet to visit, but some nodes may connect to the same node thats already in our queue, thus our visited 
//Array also keeps track of nodes in our queue
void Graph ::  bfsMat(){
    bool visited[this->adjMat.size()] = {0};
    queue<int> q;
    int i;
    cout<<0<<endl;

    visited[0] = 1;
    q.push(0);
    

    while(!q.empty()){
        i = q.front();
        q.pop();
        for( int j = 0; j < adjMat.size(); j++){
            if(adjMat[i][j] == 1 && visited[j] == 0){
                cout<<j<<" ";
                visited[j] = 1;
                q.push(j);
            }
        }
        cout<<endl;
    }
};

void Graph :: dfsMat(){
    vector<bool> visited(this->adjMat.size(),false);
    dfsHelper(0,visited);
}

void Graph :: dfsHelper(int vertex, vector<bool> & visited){    //We can either have the visited matrix as private varaible and clear it or pass by reference
    visited[vertex] = true;
    cout<<vertex<<" ";
    for( int i = 0; i < adjMat.size(); i++){
        if(this-> adjMat[vertex][i] == 1  && visited[i] == false ){ //If there exists an edge (mat[vertex][i] == 1)
            dfsHelper(i, visited);                              //  and it hasn't been visited, remember that i represents the column in this case,
                                                                //We visit that column and pass in the visted vector
        }
    }
}