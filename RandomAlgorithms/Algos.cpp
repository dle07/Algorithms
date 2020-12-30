#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Given two arrays of integers, find the minimum difference between two elements in the arrays
    Time Complexity O (nlogn)
    Idea: We want to sort the array, keep two pointers , keep track of minimum diff found so far.
    If one pointer's element is smaller than the other pointer, increment that pointer, We want to Increment the smaller pointer because we're trying to minimiize absolute difference, 
    if we increment the larger one it means that the distance (abs diff) is getting bigger which is not what we want

    1)Sort the Arrays
    2)Set two pointers at the beginning
    3)While both pointers are within the bounds of our arrays we need to compare the current difference with smallest kept so far
    4)Increment the smaller element's pointer because we want to minimze the distance between the two elements
        -If we increment the bigger element's pointer it means that the distance is increasing because the arrays are sorted!
*/
int minimumDifferenceBetweenTwoArrays(vector<int> x,vector<int>y){
    if(x.empty() || y.empty()){
        return -1;
    }
    
    sort(x.begin(),x.end());
    sort(y.begin(),y.begin());

    int res = abs(x[0] - y[0]);
    int currDiff;
    int i = 0;
    int j = 0;

    while (  i <x.size() && j < y.size()){
        currDiff = abs(x[i] - y[j]);
        if( currDiff < res)
            res = currDiff;
        if( x[i] < y[j]){
            ++i;
        }else{
            ++j;
        }
        
    }
    return res;
}

