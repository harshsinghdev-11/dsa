//get the element by row and column
#include<bits/stdc++.h>
using namespace std;

int getEle(int row,int col){
    if(col<=0) return -1;
    if(col==1 || col==row) return 1;
    int lst_value = 1;
    for(int i=1;i<col;i++){
        lst_value*=(row-i);
        lst_value/=i;
    }
    return lst_value;

}

int main(){
    cout<<getEle(5,3);
}