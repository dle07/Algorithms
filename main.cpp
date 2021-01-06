
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iterator>
#include <unordered_map>
#include <stdlib.h>  

#include <queue>

#include "./Sorting/Sort.hpp"
#include "./Sorting/Sort.cpp"

#include "./Graphs/Graph.hpp"
#include "./Graphs/Graph.cpp"

using std:: endl;
using std:: cout;
using std:: string;
using namespace std;
#include <map>



int main(){
    
    vector<int> test = {5,4,7,3,6,1,8,3,4,8,1,3,8,3,8,2,5};
    Sort::quickSort(test);
    for( int el: test){
        cout<<el<<" ";
    }
    
    
    return 0;
    
    
}
    
/*


typedef pair<int,vector<int>> pi;

class Solution {
    int calcDist(int a, int b){
        return (a*a) + (b*b);
    }
    vector<vector<int>> result;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        pi temp;
        priority_queue<pi,vector<pi>, greater<pi>> q; //min heap
        for( int i = 0; i < points.size(); i++){
            temp = pi(calcDist(points[i][0],points[i][1]), points[i] );
            if(q.size() == K){
                if( temp.first < q.top().first){
                    continue;
                }else{
                    q.push(temp);
                    q.pop();
                }
            }
        }
        while(!q.empty()){
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};

////////////

class CombinationIterator {
public:
    int it = 0;
    vector<string> combos;
    int length;
    
    void dfs( int depth, string space){
        if( depth == length){
            combos.push_back(space.substr(0,depth));
            return;
        }
        for( int i = depth; i <space.size(); i++){
            swap(space[depth],space[i]);
            dfs(depth+1,space);
            swap(space[depth],space[i]);
            
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        
        this -> length = combinationLength;
        dfs(0,characters);
    }
    
    string next() {
        return combos[it];
        ++it;
    }
    
    bool hasNext() {
        return it < combos.size();
    }
};

class Solution {
    vector<string> result;
    int n ;
    string number;
    
    vector<string> m = {"","",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"  };
    
    void dfs(string path, int depth){
        if(depth == n ){
            result.push_back(path);
            return;
        }
        string space = m[ number[depth] - '0'];
        for( int i = 0; i < space.size(); i++){
            dfs(path + space[i],depth+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return result;
        }
        this->number = digits;
        this-> n = digits.size();
        dfs("",0);
        return result;
    }
};

vector<int> myVector = {1,2,3,4,5,6,7};
    vector<int> part(myVector.begin(), myVector.begin() +2);
    cout<<part.size()<<endl;

    map<char,int> m;
    m['a'] = 10;
    m['c'] = 30;
    m['d'] = 40;
    auto it = m.upper_bound('z');
    if( it == m.end()){
        cout<<"Out of bounds"<<endl;
    }else{
        cout<<it->first<<endl;    }
    
    
   


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
    


{0,1,1,1,1,0,0},
        {1,0,1,0,0,0,0},
        {1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0},
        {1,0,0,0,0,1,0},
        {0,0,0,0,1,0,1},
        {0,0,0,0,0,1,0},

*/