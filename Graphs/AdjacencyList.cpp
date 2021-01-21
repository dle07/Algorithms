#include <list>
#include <vector>

//Another Alternative is using sets instead of lists to store the connecting edges for each vertex, 
//so our structure would be a adjacency set instead, provides log(n) lookup time for an edge
using namespace std;
//0 1 2 3 4 5 6 7


//Add an edge from 

vector<list<int>> make_adjList(int n){
    return vector<list<int>>(n, list<int>());
}

void addBiEdge(vector<list<int>> &target, int v, int u){

    if( v > target.size() || u > target.size()) return;
    for( auto it = target[v].begin(); it != target[v].end(); it++){
        if(*it == u){
            return;
        }
    }
    target[v].push_front(u);
    target[u].push_front(v);

}


void deleteBiEdge(vector<list<int>>& target, int v, int u){
    if(  v > target.size() || u > target.size()) return;

    target[v].remove(u);
    target[u].remove(v);

}