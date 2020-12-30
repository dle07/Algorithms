
#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "./Sorting/Sort.hpp"
#include "./Sorting/Sort.cpp"
#include "./Graphs/Graph.hpp"
#include "./Graphs/Graph.cpp"

using std:: endl;
using std:: cout;
using std:: string;
using namespace std;


int main(){
    vector<vector<int>> test = {
    //   0 1 2 3 4 5 
        {0,1,1,0,0,0},  //0
        {1,0,0,1,0,0},  //1
        {1,0,0,1,0,0},  //2
        {0,1,1,0,1,1},  //3
        {0,0,0,1,0,0},  //4
        {0,0,0,1,0,0}   //5
    };
    set<int> mySet;
    for( int i  =0 ; i<10; i++){
        mySet.insert(i);
    }
    auto it = mySet.begin();
    cout<<*it<<endl;
    
   
    return 0;
    
    
}

/*
{0,1,1,1,1,0,0},
        {1,0,1,0,0,0,0},
        {1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0},
        {1,0,0,0,0,1,0},
        {0,0,0,0,1,0,1},
        {0,0,0,0,0,1,0},

*/