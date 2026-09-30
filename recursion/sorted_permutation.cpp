#include <bits/stdc++.h>

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

void helper(vector<int>&nums,vector<int>&permutation,vector<bool>&flags,int &nums_size){
    if(permutation.size()==nums.size()){
        cout<<"Permutation: ";
        for(const int num:permutation){
            cout<<num;
        }
        cout<<endl;
    }
    for(int i=0;i<nums_size;i++){
        if(!flags[i]){
            flags[i]=true;
            permutation.push_back(nums[i]);
            helper(nums,permutation,flags,nums_size);
            flags[i] = false;
            permutation.pop_back();
        }
    }
    return;

}

void generateSortedPermutation(vector<int>&nums){
    quickSort(nums,0,nums.size());
    vector<int>permutation;
    vector<bool>flags(nums.size(),false);
    int nums_size = nums.size();
    helper(nums,permutation,flags,nums_size);
}

int main(){
    vector<int>nums = {3,2,4,5};
    generateSortedPermutation(nums);
}