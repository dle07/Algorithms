#include "./../classes.cpp"
#include <queue>
#include <iostream>
using namespace std;

/*
    BFS while keeping track of current depth of a node,
    1) Push the root onto the queue
    2) Push nullptr onto the queue
    3) Initilize a level variable to keep track of current level
    3) Use a while loop to traverse the tree in a breadth first manner
        -If the you encounter a nullptr in the queue, increment depth, push another nullptr
        -If you the front of the queue is another nullptr it means you've found consecutive nullptrs, break
    This works because the nullptr marks the boundary of the end of a level, because before we find the nullptr, we are pushing
    all the children first, then pushing the nullptr
*/
void bfs(TreeNode* root){
    int level = 0;
    TreeNode* curr;
    queue<TreeNode*> q;
    if(root){
        q.push(root);
    }
    q.push(nullptr);
    while(!q.empty()){
        curr  = q.front();
        if( curr = nullptr){    //nullptr marks the end of 
            ++level;
            q.push(nullptr);
            cout<<endl;
            if( q.front() == nullptr) break;//We found two consecutive nullptrs, break
            else{
                continue; //We need to stop here and continue the loop because if we don't we'll run into a nullptr exception
                //because we are trying to access a member variable of a nullptr in the below instructions
            }
        }
        cout<< "Value: "<<curr->val<<" level: "<<level;
        if( root -> right )q.push(root -> right);
        if( root -> left )q.push(root -> left);
    }

}


int main(){


    return 0;
}