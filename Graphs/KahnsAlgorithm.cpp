#include <vector>
#include <list>
#include <queue>

using namespace std;
/*
    Directed graphs can be used to represent nodes that are dependent on eachother. If a node X has a directed edge to node Y
    it means node Y is indepdent on node Y. In real world scenarios, a collection of such nodes with this relationship can represent 
    Topolgoical orderings. You must complete nodes a,b,c,d,e,f,g... inorder to complete the whole task.

    Kahns Algorithm
    -Time O(|V| + |E|)
    -Space O(|V|)
    
    A node is said to be independent if its indegree is 0. It means no nodes or "tasks" have an edge points to that node.
    
    -Interestingly Kahns algorithm kills two birds with one stone. Not only does this topoglically sort our graph,
    in the end it can tell us if there exists no possible ordering which implies this graph is cyclic.
    A cyclic graph can't be sorted because there are atleast two nodes that are dependent on eachother. 
    if our topological sequence size != |V| it means we didn't take into acocunt all nodes. Thus there's a cycle.

    1)Create an array of size |V| called inDegree that keeps track of the indegree of an element.
    2)Loop through our graph, record the in degree of each node.
    3)Maintain a queue of independent nodes (indegrees of 0)
    4)Loop thorugh our indegree array, add nodes whoses degree is 0 to our queue
    5) While !queue.empty(), add that node to our result, find the outgoing edges, reduce each destinaition's indegree by 1, if its 0,
        it means it's free, add it to our queue
*/
// adj is assumed to be a directed graph, 
vector<int> topSort(vector<list<int>>& adj, bool & hasCycle){
    vector<int> inDegree(adj.size(),0);
    vector<int> topSequence; //our final result, our ordering
    for(int i = 0; i < adj.size(); i ++){
        for( int neighbors: adj[i]){
            inDegree[neighbors]++;
        }
    }
    queue<int> q; //queue of independent ndoes
    for( int node : inDegree ){
        if( node == 0 ){
            q.push(node);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        topSequence.push_back(curr);
        for( int neighbors : adj[curr]){
            inDegree[neighbors]--;     //Look at neighbors, decrease their indegree by 1
            if( inDegree[neighbors] == 0) q.push(neighbors);
        }
    }
    if(topSequence.size() != adj.size()){  //There's a cycle, not all nodes were exhausted
        hasCycle = true;
    }else{ hasCycle = false;}

    return topSequence;
}