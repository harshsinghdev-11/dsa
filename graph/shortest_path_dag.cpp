#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<pair<int,int>>>&adj_list){
    int total_nodes = adj_list.size();
    vector<int>inDegree(total_nodes,0);
    for(int i=0;i<total_nodes;i++){
        for(auto it1:adj_list[i]){
            inDegree[it1.first]++;
        }
    }
    queue<int>q;
    for(int i=0;i<total_nodes;i++){
        if(inDegree[i]==0)q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj_list[node]){
            inDegree[it.first]--;
            if(inDegree[it.first]==0) q.push(it.first);
        }
    }
    return topo;
}

int main(){
    vector<vector<pair<int,int>>>adj_list = { {{1,2}}, {{3,1}},{{3,3}},{},{{0,3},{2,1}}, {{4,1}},{{4,2},{5,3}} };
    // pair<int,int> = {node,distance}
    int src_node = 6;
    int total_nodes = adj_list.size();
    vector<int>topo = topoSort(adj_list);
    vector<int>shortest_distance(total_nodes,INT_MAX);
    shortest_distance[src_node] = 0;
    for(int i=0;i<total_nodes;i++){
        int node = topo[i];
        for(auto it:adj_list[node]){
            if(shortest_distance[it.first]> (it.second+shortest_distance[node])){
                shortest_distance[it.first] = it.second+shortest_distance[node];
            }
        }
    }
    for(int i=0;i<total_nodes;i++){
        cout<<"Distance from 6 to "<<i<<": "<<shortest_distance[i]<<endl;
    }

}