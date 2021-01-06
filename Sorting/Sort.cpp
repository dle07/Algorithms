#include "Sort.hpp"

int getRandomPivot(int a, int b){//Helper function to generate a random pivot in ranges of [a,b]
    return (rand()%(b-a+1)) + a;
}



void Sort :: print(std :: vector<int>& vecInput){
    std :: cout<<"Printing Contents of Vector"<<std :: endl;
    for( auto el: vecInput){
        std :: cout<< el<< std :: endl;
    }

}


void Sort :: selectionSort(std :: vector<int>& vecInput){
        int n=vecInput.size();
        int currMin;
        int currMinIndex;

        //Loop through each element in the vector, the unsorted vector is i to n, find the smallest value, replace it with i
        for( int i=0; i<vecInput.size(); i++){
            currMin = vecInput[i];
            currMinIndex = i;
            for( int j=i; j< vecInput.size() ; j++){
                if( vecInput[j] < currMin){
                    currMin = vecInput[j];
                    currMinIndex = j;
                }
            }
            swap(&vecInput[i], &vecInput[currMinIndex]);
        }
    }


void Sort:: bubbleSort(std :: vector<int>& vecInput){

    bool continueSwapping = true;
    int pass = 1;       //keep track of passes,
    while( continueSwapping ){ // because for every iteration the domain of the 
                                //unsorted array decreases by one because the largest element
        continueSwapping = false;
        
        for( int i=0; i<vecInput.size()-pass; i++){ //decreases domain by one for each iteration
            if( vecInput[i+1] < vecInput[i]){       //if element ahead of index is greater, i n i t i a t e SWAP!
                swap(&vecInput[i], &vecInput[i+1]);
                continueSwapping = true;
            }
        }
        pass ++;

    }
}



/*
    With insertion sort we are creating two subsets, a sorted set, and a unsorted set
    We iterate through all the values of the array, mark the position of that value, then loop backwards and shift all elements greater than the value observed( stored into a temporary varaible)
    We then finally set the position to the temporary value, effectively inserting (by shifting) the element into our sorted set.

*/
void Sort :: insertionSort(std ::vector<int>& vecInput){
    int j=0;
    int temp;
    for( int i=0; i< vecInput.size() - 1; i++){
        temp = vecInput[i];
        j = i;
        while( j > 0 && vecInput[j-1] > temp ){
            vecInput[j] = vecInput[j-1];
            j--;
        }
        vecInput[j] = temp;
    }

}




void Sort :: quickSort (std :: vector <int> & vecInput){ //Modularity, not actual implementation
    quickSortImpl(vecInput,0,vecInput.size()-1);
}


void Sort :: quickSortImpl(std :: vector<int>& vecInput, int start, int end){
    if(start<end){ // If the first index is less than last it means the size is >=2
        int part = partition(vecInput,start,end);
        quickSortImpl(vecInput, start, part-1);
        quickSortImpl(vecInput,part+1,end);
    }

}

//Our pivot can be anything, but for better performance lets pick a random pivot
int Sort :: partition(std :: vector<int> &vecInput, int start, int end){ //Picks last element for partition, p = ((end-start)/2)+start;
    int p = getRandomPivot(start,end);
    int pivot = vecInput[p];
    swap(&vecInput[p],&vecInput[end]);

    int i = start; //keeps track of index where if an element was lesser than pivot, we should swap it
    int j = start;
    while( j < end){
        if( vecInput[j]<pivot){
            swap(&vecInput[i],&vecInput[j]);
            i++;
        }
        ++j;
    }
    swap(&vecInput[i],&vecInput[end]);
    return i; //This is the index of the parition, its now in its right place.
}

void Sort :: swap(int* a, int*b){
    int temp = *a;      //stores the value of a,
    *a = *b;            //set a to b
    *b = temp;          //set b to a's initial value
}


//Recursive Divide and conquer, The process of merging is linear,The number of merges performed is proportional to log2(n)
void Sort :: mergeSort(std :: vector<int>& vecInput){
    int n = vecInput.size();
    if( n < 2) return;  //exit condition;
    int mid = n/2;
    std :: vector<int> left;
    std :: vector<int> right;
    mergeSort(left);
    mergeSort(right);
    merge(left,right,vecInput);
}


void Sort:: merge(std :: vector<int>&left, std :: vector<int> &right, std :: vector<int> &actual){

    int i = 0; 
    int j = 0;
    int k=0;
    while(i < left.size() && j < right.size()){
        if( left[i] <= right[j]){
            actual[k] = left[i];
            i++;
        }else{
            actual[k] = right[j];       //else if( left[i] > right[j])
            j++;
        }
        k++;
    }
    while( i< left.size()){
        actual[k] = left[i];
        i++;
        k++;
    }
    while( j < right.size()){
        actual[k] = right[j];
        j++;
        k++;
    }
}


