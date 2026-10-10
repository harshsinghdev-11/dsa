#include<bits/stdc++.h>
using namespace std;

bool detectCycle(vector<vector<int>>&adj,int V){
    vector<int>inDegree(V,0);
    for(int i=0;i<V;i++){
        for(int it:adj[i]){
            inDegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0) q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0)q.push(it);
        }
    }
    return topo.size()!=V;
}

int main(){
    vector<vector<int>>edges =  {{0, 1}, {1, 2}, {2,4},{3, 1}, {2, 3}};
   int V = 5, E = 5;
   vector<vector<int>>adjancency_list(V);
    for(int i=0;i<E;i++){
        adjancency_list[edges[i][0]].push_back(edges[i][1]);
    }
    cout<<detectCycle(adjancency_list,V);
}
