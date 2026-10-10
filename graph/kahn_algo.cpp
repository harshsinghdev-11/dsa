#include<bits/stdc++.h>
using namespace std;

vector<int>topoSort(vector<vector<int>>adj,int V){
    vector<int>inDegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
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
            if(inDegree[it]==0) q.push(it);
        }
    }
    return topo;

}

int main(){
    vector<vector<int>>edges =  {{1, 3}, {2, 3}, {4, 1},{4, 0}, {5, 0}, {5, 2}};
   int V = 6, E = 6;
   vector<vector<int>>adjancency_list(V);
    for(int i=0;i<E;i++){
        adjancency_list[edges[i][0]].push_back(edges[i][1]);
    }
   vector<int>topo = topoSort(adjancency_list,V);
   for(int it:topo){
    cout<<it<<" ";
   }
}