#include "Graph.hpp"



Graph :: Graph(){
};
Graph :: Graph(int n){
    this->adjList = make_adjList(n);
    this->parent = vector<int>(n, -1);
    this-> level = vector<int>(n, -1);
}
Graph :: Graph(vector<vector<int>> adjacencyMatrix,int n){
    this->adjList = make_adjList(n);
    this-> adjMat = adjacencyMatrix;
    this -> parent = vector<int>(adjList.size(),-1);
    this -> level = vector<int>(0,-1);
    
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


void Graph :: bfsList(int startVertex){

    this->reset();
    int depth = 0;
    if( startVertex > adjList.size()) return;
    queue<int> q;   //If a node is on the queue it means we shouldn't explore it as its already queued to be explored
    int curr;
    
    parent[startVertex] = startVertex; //mark startVertex as explored/being explored
    q.push(startVertex);            //push onto queue
    q.push(-1); //push -1 onto the queue to represent that the end of a layer is detected, so increment depth by 1

    level[startVertex] = depth;
    while(!q.empty()){
        curr = q.front();
        if( curr == -1){
            ++depth;
            q.push(-1);
            q.pop();
            if(q.front() == -1)break; //We see two -1s, stop and break, nothing else in the queue
            else{ continue; }
        }
        level[curr] = depth;
        for( int next : adjList[curr]){  //We need to push all un explored vertices of the current vertex onto the queue and mark its parent
            if( parent[next] == -1){  //means it has yet to be explored, we set the parent of next to be the curr node, this keeps track of the path and marks it as being visited. We then push it onto the queue inorder to visit it in the future
                parent[next] = curr;
                q.push(next);
            }
        }     
        q.pop();   
    }

}

string Graph :: reconstructPath(int end){
    if( parent[end] == -1)return ""; // No Path
    string result;
    result += to_string(end);

    while( parent[end] != end){
        result += ">-" + to_string(parent[end]) ;
        end = parent[end];
    }
    reverse(result.begin(), result.end());
    return result;
}


void Graph :: reset(){
    for(int i = 0; i < parent.size(); i++){
        parent[i] = -1;
        level[i] = -1;
    }
}