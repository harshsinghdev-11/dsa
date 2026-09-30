#include <bits/stdc++.h>
using namespace std;

// [3,2,4,5,6]
//need to generate all permutation in sorted order

void generatePermutation(vector<int>&nums,vector<bool>&flag,vector<int>&permutation,int nums_size){
    if(permutation.size()==nums.size()){
        cout<<"Next Permutation: ";
        for(const int num:permutation){
            cout<<num;
        }
        cout<<endl;
    }
    for(int i=0;i<nums_size;i++){
        if(!flag[i]){
            permutation.push_back(nums[i]);
            flag[i] = true;
            generatePermutation(nums,flag,permutation,nums_size);
            flag[i] = false;
            permutation.pop_back();
        }
    }
    return;
    
    
}

int main(){
    vector<int>nums = {3,2,4,5};
    vector<int>permutation;
    vector<bool>flag(nums.size(),false);
    generatePermutation(nums,flag,permutation,nums.size());
}