#include<iostream>
#include<vector>
#include <climits>
using namespace std;

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

//brute approach
int brutemaxSubArray(vector<int>&nums){
    //brute approach
    int max_sum = INT_MIN;
    int nums_size = nums.size();
    for(int i=0;i<nums_size;i++){
        for(int j=i;j<nums_size;j++){
            int temp_sum = 0;
            for(int k=i;k<=j;k++){
                temp_sum+=nums[k];
            }
            max_sum=max(max_sum,temp_sum);
        }
    }
    return max_sum;
}

//optimal brute force
int optimalMaxSubArray(vector<int>&nums){
    int max_sum = INT_MIN;
    int nums_size = nums.size();
    for(int i=0;i<nums_size;i++){
        int temp_sum1 = 0;
        for(int j=i;j<nums_size;j++){
            temp_sum1+=nums[j];
            
            max_sum=max(max_sum,temp_sum1);
        }
    }
    return max_sum;
    
}

//best -> kadane's algo
int maxSubArray(vector<int>&nums){
    int sum=0;
    int ans = 0;
    int maxi=INT_MIN;
    int nums_size = nums.size();
    for(int i=0;i<nums_size;i++){
        sum+=nums[i];
        if(sum<0) sum=0;
        ans=max(ans,sum);
        maxi = max(maxi,nums[i]);
    }
    return ans==0?maxi:ans;
}

int main(){
    vector<int>v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<brutemaxSubArray(v)<<endl;
    cout<<optimalMaxSubArray(v)<<endl;
    cout<<maxSubArray(v);
}