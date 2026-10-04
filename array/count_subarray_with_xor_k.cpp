#include <bits/stdc++.h>

using namespace std;

//most brute force = three nested for loop
int bruteForce(vector<int>&arr,int k){
    int cnt = 0;
    int arr_size = arr.size();
    for(int i=0;i<arr_size;i++){
        for(int j=i;j<arr_size;j++){
            int xor_val = 0;
            for(int m=i;m<=j;m++){
                xor_val^=arr[m];
            }
            if(xor_val==k) cnt++;
        }
    }
    return cnt;
}

int optimalBruteForce(vector<int>&arr,int k){
    int cnt = 0;
    int arr_size = arr.size();
    for(int i=0;i<arr_size;i++){
        int xor_val = 0;
        for(int j=i;j<arr_size;j++){
            xor_val^=arr[j];
            if(xor_val==k) cnt++;
        }
    }
    return cnt;
}

int optimalCount(vector<int>&arr,int k){
    int cnt = 0;
    unordered_map<int,int>map;
    map[0] = 1;
    int arr_size = arr.size();
    int xor_val = 0;
    for(int i=0;i<arr_size;i++){
        xor_val^=arr[i];
        int temp_xor = xor_val^k;
        if(map.find(temp_xor)!=map.end()){
            cnt+=map[temp_xor];
        }
        map[xor_val]++;
    }
    return cnt;
}

int main(){
    vector<int>arr = {4,2,2,6,4};
    vector<int>arr2 = {1,2,3,2};

    // cout<<optimalCount(arr,6)<<endl;
    // cout<<optimalCount(arr2,2)<<endl;

    // cout<<optimalBruteForce(arr,6)<<endl;
    // cout<<optimalBruteForce(arr2,2)<<endl;

    cout<<bruteForce(arr,6)<<endl;
    cout<<bruteForce(arr2,2)<<endl;

}