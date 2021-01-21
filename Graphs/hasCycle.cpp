#include <list>
#include <vector>

using namespace std;
//

//Modified DFS to perform dfs and check if a edge is is a back edge
bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack, vector<list<int>>& adj ){ 
    if(!visited[v]){ // Exit condition

        recStack[v] = true; //Push onto our stack
        visited[v]  = true; //Mark as visited

        for( int neighbors : adj[v] ){   //Loop through all neighbors of the current vertex
            if(recStack[neighbors] == true || isCyclicUtil(neighbors, visited, recStack, adj)) // If the neighborm aka a destination vertex is in our current path (recStack) return false
                return true;    //Call isCyclicUtil on neighbors, to recursively search the graph
        }
    }
    recStack[v] = false; //Remove it from our recStack
    return false;
}


bool hasCycle(vector<list<int>>& adj){

    int n = adj.size();
    vector<bool> visited(n,false);
    vector<bool> recStack(n,false);
    //Deals with disconnected components by calling the modified dfs on all vertices
    for( int i = 0; i < n ;i++){
        if(isCyclicUtil(i, visited, recStack, adj)) return true;
    }

    return false;
}