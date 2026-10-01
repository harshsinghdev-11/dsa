#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> printRow(int row){
    vector<int>ans;
    ans.push_back(1);
    int lst_value = 1;
    for(int i=1;i<row;i++){
        lst_value = lst_value*(row-i);
        lst_value/=i;
        ans.push_back(lst_value);
    }
    return ans;
}
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle;
       for(int i=1;i<numRows+1;i++){
        vector<int>temp = printRow(i);
        triangle.push_back(temp);
       }
        return triangle;
    }
};

int main(){
    Solution s;
    vector<vector<int>>pascal_triangle = s.generate(10);
    for(int i=0;i<pascal_triangle.size();i++){
        for(int j=0;j<pascal_triangle[i].size();j++){
            cout<<pascal_triangle[i][j]<<" ";
        }
        cout<<endl;
    }
}

