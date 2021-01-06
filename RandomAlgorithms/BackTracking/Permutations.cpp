#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iterator>
#include <unordered_map>

using namespace std;
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