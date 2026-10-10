//adjanceny list    
//visited
//stack
//dfs
// at the time of backtracking put ele in stack
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&list,vector<bool>&isVisited,int r,stack<int>&st){
    if(isVisited[r]) return;
    isVisited[r] = true;

    for(int i:list[r]){
        dfs(list,isVisited,i,st);
    }
    st.push(r);
}

int main(){
    vector<vector<int>>edges =  {{1, 3}, {2, 3}, {4, 1},{4, 0}, {5, 0}, {5, 2}};
   int V = 6, E = 6;
   vector<vector<int>>adjancency_list(V);
    for(int i=0;i<E;i++){
        adjancency_list[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool>isVisited(V,false);
    stack<int>st;
    for(int i=00;i<V;i++){
        if(!isVisited[i]){
            dfs(adjancency_list,isVisited,i,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}