#include<bits/stdc++.h>
using namespace std;

//brute force
vector<int> brute(vector<int>&a){
    int a_size = a.size();
    int repeating_value = 0;
    int misssing_value = 0;
    for(int i=1;i<a_size+1;i++){
        int cnt=0;
        for(int j=0;j<a_size;j++){
            if(a[j]==i) cnt++;
        }
        if(cnt>1) repeating_value = i;
        if(cnt==0) misssing_value = i;
    }
    return {repeating_value,misssing_value};
}

int partition(vector<int>&a,int low,int high){
    int pivot = a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[low]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

//binary search -> only finding the repeating value = sorting then binary search without extra space
//with extra space it can done through map or set
void quickSort(vector<int>&a,int low,int high){
    if(low<high){
        int partition_val = partition(a,low,high);
        quickSort(a,low,partition_val-1);
        quickSort(a,partition_val+1,high);
    }
}

vector<int> binary_search_method(vector<int>&a){
    int a_size = a.size();
    quickSort(a,0,a_size-1);
    int low = 0;
    int high =a_size;
    int missing_value = 0;
    int repeated_value = 0;
    while(low<high){
        int mid = low + (high-low)/2;
        if(a[mid]==mid+1){
            low =mid+1;
        }else{
            missing_value = mid;
            repeated_value = a[mid];
            high = mid-1;
        }
    }
    return {repeated_value};
}

//by maths
vector<int> math_method(vector<int>&a){
    long long a_size = a.size();

    long long sum_n = a_size/2;
    long long a_sum_sq = 0;
    sum_n *=a_size+1;
    long long a_sum = 0;
    for(int num:a){
        a_sum+=num;
        a_sum_sq+=num*num;
    }
    long long sum_sq_n = a_size * (a_size + 1) * (2 * a_size + 1) / 6;
    int diff1 = sum_n-a_sum;
    int diff2 = sum_sq_n-a_sum_sq;
    diff2/=diff1;
    int num1 = (diff2+diff1)/2;
    int num2 = -(diff1-num1);
    int cnt=0;
    for(int temp_num:a){
        if(temp_num==num1)cnt++;
    }
    if(cnt>1)return {num1,num2};
    return {num2,num1};
}




vector<int> findMissingRepeatingNumber(vector<int>a){
    int a_size = a.size();
    int xr = 0;
    for(int i=0;i<a_size;i++){
        xr^=a[i];
        xr^=(i+1);
    }
    int bitNumber = 0;
    while(1){
        if( (xr & (1<<bitNumber)) != 0){
            break;
        }
        bitNumber++;
    }
    int zero = 0;
    int one = 0;
    for(int i=0;i<a_size;i++){
        if((a[i]&(1<<bitNumber))!=0){
            one^=a[i];
        }else{
            zero^=a[i];
        }
    }
    for(int i=1;i<a_size+1;i++){
        if((i&(1<<bitNumber))!=0){
            one^=i;
        }else{
            zero^=i;
        }
    }
   
    int cnt=0;
    for(int num:a){
        if(num==one) cnt++;
    }
    if(cnt>1){
        return {one,zero};
    }
    return {zero,one};

}

int main(){
    vector<int>a = {4,3,6,2,1,1};
    vector<int>repeating = findMissingRepeatingNumber(a);
     cout<<"Repeating value: "<<repeating[0]<<" Missing value is: "<<repeating[1];
     cout<<endl;
     vector<int>repeating1 = brute(a);
     cout<<"Repeating value: "<<repeating1[0]<<" Missing value is: "<<repeating1[1];
     cout<<endl;
     vector<int>repeating2 = binary_search_method(a);
     cout<<"Repeating value: "<<repeating2[0];
     cout<<endl;
     vector<int>repeating3 = math_method(a);
     cout<<"Repeating value: "<<repeating3[0]<<" Missing value is: "<<repeating3[1];
}