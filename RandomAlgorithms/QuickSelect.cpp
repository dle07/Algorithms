/*
    Quick select uses quick sort's parition idea to find the of the kth largest or smallest value of an array
    If the pivot index is equal to the target index, it means that everything left to that array is lesser than the pivot value,
    everything to the right is greater or equal to to the pivot value;
    Time - O(n) Space O(1)
    Note: We know absolutely nothing about the ordering of elements to the right and left of the pivot index if found!
*/
#include <iostream>
#include <vector>
#include <stdlib.h>  //Random Number
#include <algorithm>
using namespace std;

enum placement{
    greatest,
    smallest
};
void swap(int*a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getRandomPivot(int a, int b){//Helper function to generate a random pivot in ranges of [a,b]
    return (rand()%(b-a+1)) + a;
}

int getKthIndex(vector<int>& vec, int k, placement placementType = greatest){ //By default this will find the kth greastest
    if( k > vec.size())return -1;
    bool found = false;
    int target;
    int start = 0;
    int end = vec.size()-1;
    int pivot;
    int pivotValue;

    int i;
    int j;
    if( placementType == greatest){
        target = vec.size()-k;
    }else{
        target = k-1;
    }

    while(!found){
        i = start;
        j = start;
        pivot = getRandomPivot(start,end);
        pivotValue = vec[pivot]; //Value we need to compare for;
        swap(&vec[pivot] , &vec[end]); //Sends pivot element to the very end
        while( j < end ){
            if( vec[j] < pivotValue){  //If the oberseved value is less than the pivot value we need to push it all the way to the right by swapping
                swap(&vec[i],&vec[j]);
                i++;
            }
            ++j;
        }

        swap(&vec[i],&vec[end]);
        pivot = i;
        if( pivot == target){
            return pivot;
            found = true;
        }
        if( pivot < target){
            start = pivot+1;
        }else{
            end = pivot-1;
        }
    }
    return -1;
}

int main(){
    //1,3,4,4,5,6,6,8,8,9
    cout<<"Hello"<<endl;
    vector<int> test = {4,6,8,3,9,1,6,5,8,4};
    int index = getKthIndex(test,2);
    cout<<test.size()<<endl;
    cout<<index<<endl;
    return 0;
}


