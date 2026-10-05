// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] >  nums[j].
// nums = [3,1,2,5,4]

#include<bits/stdc++.h>
using namespace std;

// M2 -> using stack

int merge(vector<int>&arr,int left,int mid,int high){
    int n1 = mid-left+1;
    int n2 = high-mid;
    int low = left;
    vector<int>temp_vec;
    int i=0;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right] ){
            temp_vec.push_back(arr[left]);
            left++;
        }else{
            cnt+=(mid-left+1);
            temp_vec.push_back(arr[right]);
            right++;
        }
        
    }
    while (left <= mid) {
        temp_vec.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp_vec.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp_vec[i-low];
    }
    return cnt;
}

int mergeSort(vector<int>&arr,int left , int right){
    if(left>=right){
        return 0;
    }
    int cnt=0;
    int mid = left+ (right-left)/2;
    cnt+=mergeSort(arr,left,mid);
    cnt+=mergeSort(arr,mid+1,right);
    cnt+=merge(arr,left,mid,right);
    return cnt;
}

// M1
int count_inversion(vector<int>&nums){
    return mergeSort(nums,0,nums.size()-1);
}

int main(){
    vector<int>nums = {3,1,2,5,4};
    cout<<count_inversion(nums);
}