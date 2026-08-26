#include <iostream>
#include<vector>
#include <algorithm>

int minArrow(std::vector<std::vector<int>>&ballons){
    sort(ballons.begin(),ballons.end(),[](std::vector<int>&a,std::vector<int>&b){
        return a[1]<b[1];
    });
    int arrow = 1;
    int end = ballons[0][1];
    int ballons_size = ballons.size();
    for(int i=1;i<ballons_size;i++){
        //if overlap
        if(ballons[i][0]<=end){
            continue;
        }else{
            arrow+=1;
            end = ballons[i][1];
        }
    } 
    return arrow;
}

int main(){
    std::vector<std::vector<int>>points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    std::cout<<minArrow(points);
    return 0;
}