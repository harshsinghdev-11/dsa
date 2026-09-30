#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&nums,int low,int high){
    int pivot = nums[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(nums[j]<pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }

    swap(nums[i+1],nums[high]);
    return i+1;
}

void quickSort(vector<int>&nums,int low,int high){
    if(low<high){
        int pi = partition(nums,low,high);
        quickSort(nums,low,pi-1);
        quickSort(nums,pi+1,high);
    }
}

int main(){
    vector<int>arr = {12,5,8,6,89,1};
    int high = arr.size();
    quickSort(arr,0,high-1);
    for(int num:arr){
        cout<<num<<" ";
    }
}