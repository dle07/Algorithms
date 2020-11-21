#ifndef SORT_
#define SORT_
#include <vector>
#include <iostream>




class Sort{
    /*                       Best Case     Worst Case
    Selection Sort           O(n^2)        O(n^2)
    Bubble Sort              O(n)          O(n^2)
    Insertion Sort           O(n)          O(n^2)

    */
    public:
    static void print( std :: vector <int> &vecInput);
    static void selectionSort(std :: vector<int>& vecInput);    
    static void bubbleSort(std :: vector<int>& vecInput);
    static void insertionSort(std :: vector<int>& vecInput);
    static void mergeSort(std :: vector<int>& vecInput);
    static void quickSort( std :: vector<int>& vecInput);

    
   
    //Helper Functions
    private:
    static void quickSortImpl (std :: vector<int>& vecInput);
    static void swap(int* a, int*b);
    static void merge( std :: vector<int> & left, std::vector<int> &right, std :: vector<int> &actual);
    static void partition(std :: vector<int> vecInput, int start, int end);
};

#endif