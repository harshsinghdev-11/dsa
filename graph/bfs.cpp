#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//for single component graph , not for connected graph

void dfs(vector<vector<int>>&adj){
    int total_nodes = adj.size();

    vector<bool>visited(total_nodes,false);
    queue<int>q;
    int src = 0;
    visited[src] = true;
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<"current ele: "<<curr<<endl;
        for(int x:adj[src]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return;
}

int main(){

    return 0;
}