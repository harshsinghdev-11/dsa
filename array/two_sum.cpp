// You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> bruteTwoSum(vector<int>&nums,int target){
    int nums_size = nums.size();
    for(int i=0;i<nums_size;i++){
        int num1 = nums[i];
        for(int j=i;j<nums_size;j++){
            if(i!=j){

                if(num1+nums[j]==target){
                    return {i,j};
                }
            }
        }
    }
    return {};
}

vector<int> optimalTwoSum(vector<int>&nums,int target){
    unordered_map<int,int>map;
    int nums_size = nums.size();
    for(int i=00;i<nums_size;i++){
        map[nums[i]]=i;
    }
    for(int i=0;i<nums_size;i++){
        if(map[target-nums[i]]!=i){
            return {i,map[target-nums[i]]};
        }
    }
    return {};
}

vector<int>bestTwoSum(vector<int>&nums,int target){
    unordered_map<int,int>store_index;
    int nums_size = nums.size();
    for(int i=0;i<nums_size;i++){
        if(store_index.count(target-nums[i])){
            return {i,store_index[target-nums[i]]};
        }
        store_index[nums[i]]=i;
    }
    return {};
}


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

// for variety -> where yes or no is return than greedy approach
// sort it , use two pointer from start and end
bool twoSum(vector<int>&nums,int target){
    int high = nums.size();
    quickSort(nums,0,high-1);
    int i=0;
    int j=high-1;
    while(i<j){
        if(nums[i]+nums[j]==target) return true;
        else if(nums[i]+nums[j] > target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}


int main(){
    vector<int>nums={2,7,11,15};
    
    vector<int>ans = bruteTwoSum(nums,9);
    for(int num:ans){
        cout<<num;
    }
    cout<<endl;
    vector<int>ans2 = optimalTwoSum(nums,9);
    for(int num:ans2){
        cout<<num;
    }
    cout<<endl;
    vector<int>ans3 = bestTwoSum(nums,9);
    for(int num:ans3){
        cout<<num;
    }
    cout<<endl;
    cout<<twoSum(nums,9);
}