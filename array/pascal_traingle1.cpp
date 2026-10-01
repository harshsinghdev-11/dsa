//generate nth row of pascal triangle
#include <bits/stdc++.h>
using namespace std;

void printRow(int row){
    cout<<"1"<<" ";
    int lst_value = 1;
    for(int i=1;i<row;i++){
        lst_value = lst_value*(row-i);
        lst_value/=i;
        cout<<lst_value<<" ";
    }
}

int main(){
    printRow(1);
}