#include <vector>
#include <iostream>
using namespace std;


/* Given an array from 1,2,3,.n-1,n
This is essentially a find all permutations problem but with a constraint, that either 
-The number at the ith position is divisible by i.
-i is divisible by the number at the ith position.

Thought Process, we should try and produce all possible permutations of the array using back tracking and swapping
Base cases
    -depth == end
        res ++;
        return;
    -Either of two conditions aren't met, just return;
        return;
*/

class Solution_526_Beautiful_Arrangement {
    void swap(vector<int> target, int x, int y){
        int temp = target[x];
        target[x] = target[y];
        target[y] = temp;
    }

    bool check(int element, int i){
        return ((element % i == 0) || (i % element ==0));
    }

    int end; //end of the permutation array 
    int res = 0;
    void dfs(vector<int> space, int depth){
        if( depth == end +1 ){
            res++;
            return;
        }
        
                    
        for( int i = depth; i<=end; i++){
            this -> swap(space, depth, i);
            if( check(space[i],depth)){ //Constraint condiiton, 
                dfs(space,depth+1);
            }
            this -> swap(space, depth, i);//Back Track
        }

    }
public:
    int countArrangement(int n) {
        vector<int> set = {0};
        end = n;
        for( int i = 1; i <= n; ++i){
            set.push_back(i);
        }
        dfs(set, 1);

        return res;
    }
};

int main(){
    Solution_526_Beautiful_Arrangement test;
    cout<<test.countArrangement(7)<<endl;

    return 0;
}

/*



*/