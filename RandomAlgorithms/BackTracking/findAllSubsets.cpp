/*
    -Find the powerset of a given set (can be represented as a vector, or whatver)
    -Find powerset of a set that may have duplicates

    We can find all binary string representations where the index of the string correspeonds to the element ,
    and 1 or 0 represents whether or not we include the element or not

*/
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//Helper Function to create bit representation of each combination
void solveBitRepresetnation(int n, vector<string>& storage, string path){ //n represents the size of the set we want to stop at
    //We have a full subset
    if(path.size() == n){
        storage.push_back(path);
        return;
    }
    solveBitRepresetnation(n, storage, path + "1");
    solveBitRepresetnation(n, storage, path + "0");
}

//Time Complexity = O(n x n^2)
vector<vector<int>> findPowerSet_BitRepresentation(vector<int> set){
    vector<string> storage;
    solveBitRepresetnation(set.size(),storage, "" ); //Solve for all combinations store in storage vector

    vector<vector<int>> res;
    vector<int> temp;
    //Deconstruct the powersets
    for(string combination: storage){
        temp.clear();
        for( int i = 0; i <combination.size(); ++i){
            if(combination[i] == '1'){
                temp.push_back(set[i]);
            }
        }
        res.push_back(temp);
    }
    return res;
}


//May or may not have duplicates
vector<vector<int>> findPowerSetWithDuplicates(vector<int> set){
    //Same algorithm in the above, except we need to extract all the unique elments from the given array
    unordered_set<int> mySet;
    for( int el: set){
        mySet.insert(el);
    }
    set.clear();
    for(int el: mySet){
        set.push_back(el);
    }
    return findPowerSet_BitRepresentation(set);
}

/*
    We also have a faster solution that doesn't require us to convert the bit representation to a element in the subset
    In order to do this we have to keep track of the current size of the path even if we haven't added anything, even if the true path size is less than the current recursive iteration
    so we'll pass a integer named depth, if depth is equal to the size of the set, push the path onto the matrix and return
*/
// NO BIT REPRESENTATION
void solveUsingBackTracking(int n,vector<vector<int>>& storage,vector<int>& set, vector<int>path, int depth){
    if( depth == n){
        storage.push_back(path);
        return;
    }
    //Two choices, we either push the element or not
    path.push_back(set[depth]);
    solveUsingBackTracking(n, storage,set,path,depth+1);
    path.pop_back(); //Back tracks by popping it 
    solveUsingBackTracking(n, storage,set, path, depth+1);

}
vector<vector<int>> findPowerSetNoBits(vector<int> set){

    vector<vector<int>> storage;
    solveUsingBackTracking(set.size(), storage, set, vector<int>(), 0);
    return storage;
}

