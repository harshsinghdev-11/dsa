#include <bits/stdc++.h>
using namespace std;

class SortingStrategy{
public:
    virtual void sort(vector<int>&arr,int size)=0;
    virtual ~SortingStrategy() = default;
};

class SortingContext{
private:
    SortingStrategy* sortingStrategy;
public:
    SortingContext(SortingStrategy* strategy): sortingStrategy(strategy){
       
    }

    void setSortingStrategy(SortingStrategy* strategy){
       this->sortingStrategy = strategy;
    }

    void performSorting(vector<int>&arr,int size){
        if(sortingStrategy){
            sortingStrategy->sort(arr,size);
        }
    }
};

class BubbleSort : public SortingStrategy{
public:
    void sort(vector<int>&arr,int size) override{
        cout<<"bubble sorting......"<<endl;
    }
};

class QuickSort : public SortingStrategy{
public:
    void sort(vector<int>&arr,int size) override{
        cout<<"Quick sorting..."<<endl;
    }
};

int main(){
    vector<int>nums = {1,2,3,44};
    SortingContext sortingContext(new BubbleSort());

    sortingContext.performSorting(nums,nums.size());

    sortingContext.setSortingStrategy(new QuickSort());
    sortingContext.performSorting(nums,nums.size());

}

