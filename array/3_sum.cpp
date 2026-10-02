#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

vector<vector<int>> bruteThreeSum(vector<int>&nums){
    int nums_size=nums.size();
    vector<vector<int>>ans;
    set<vector<int>>st;
    for(int i=0;i<nums_size;i++){
        for(int j=i+1;j<nums_size;j++){
            for(int k=j+1;k<nums_size;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>temp_vec = {nums[i],nums[j],nums[k]};
                    sort(temp_vec.begin(),temp_vec.end());
                    st.insert(temp_vec);
                }
            }
        }
    }
    for(auto &it:st){
        ans.push_back(it);
    }
    return ans;
}

vector<vector<int>>optimalThreeSum(vector<int>&nums){
    int nums_size = nums.size();
    set<vector<int>>hashset;
    for(int i=0;i<nums_size;i++){
        set<int>st;
        for(int j=i+1;j<nums_size;j++){
            int third_ele = -(nums[i]+nums[j]);
            if(st.find(third_ele)!=st.end()){
                vector<int>temp = {nums[i],nums[j],third_ele};
                sort(temp.begin(),temp.end());
                hashset.insert(temp);
            }
            st.insert(nums[j]);
        }
    }
    vector<vector<int>>ans(hashset.begin(),hashset.end());
    return ans;
}

int main(){
    vector<int>nums = {-1,0,1,2,-1,-4};
    vector<vector<int>>arr = bruteThreeSum(nums);
    for(vector<int> num:arr){
        for(int temp:num){
            cout<<temp<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>>arr2 = optimalThreeSum(nums);
    for(vector<int> num:arr2){
        for(int temp:num){
            cout<<temp<<" ";
        }
        cout<<endl;
    }
}