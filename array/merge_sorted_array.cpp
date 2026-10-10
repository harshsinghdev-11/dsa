#include<bits/stdc++.h>
using namespace std;

//merge the sorted array

//test case -1 
// input- arr1 = [1,3,5,7] , arr2 = [0,2,6,8,9]
// output - arr1 = [0,1,2,3] , arr2 = [5,6,7,8,9]

void gapMethod(vector<int>&arr1,vector<int>&arr2){
    int arr1_size = arr1.size();
    int arr2_size = arr2.size();
    int gap= ceil((arr1_size+arr2_size)/2);
    while(gap>0){
        int left = 0;
        int right = gap;
        while(right<(arr1_size+arr2_size)){
            if(left>arr1_size-1){
                if((arr2[left-arr1_size]>arr2[right])){
                    swap(arr2[left-arr1_size],arr2[right]);
                }
            }
            //both present in arr1,arr1
            else if(left<arr1_size && (left+gap<arr1_size)){
                if(arr1[left]>arr1[right]){
                    swap(arr1[left],arr1[right]);
                }
            }
            else{
                if((arr1[left]>arr2[right])){

                    swap(arr1[left],arr2[right]);
                }
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap=ceil(gap/2);
    }


}

int main(){
    vector<int>arr1={1,3,5,7};
    vector<int>arr2 = {0,2,6,8,9};
    gapMethod(arr1,arr2);
    for(int num:arr1){
        cout<<num<<" ";
    }
    cout<<endl;
    for(int num:arr2){
        cout<<num<<" ";
    }

}