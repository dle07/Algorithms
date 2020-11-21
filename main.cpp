
#include <iostream>
#include <vector>
#include <string>

#include "./Sorting/Sort.hpp"
#include "./Sorting/Sort.cpp"
using std:: endl;
using std:: cout;
using std:: string;


class Test{

    public:
    static void print(){
        cout<<"Hello"<<endl;
        
    }
    static void change(std :: vector<int> & test){
        for( int i=0; i<test.size() ; i++){
            test[i] = 0 ;
        }
    }
};


int main(){
    Test::print();
    std :: vector<int> test{10,9,8,7,6,5,4,3,2,1,34,5,6,7,8,8,5,5,5,5,5,5,5,5,5,5,5,5,5};
    Sort::selectionSort(test);

    Sort::print(test);
    return 0;
}