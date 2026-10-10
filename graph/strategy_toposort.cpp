#include<bits/stdc++.h>
using namespace std;

class TopoStrategy{
    public:
        virtual vector<int> topoSort(vector<vector<int>>&adjList)=0;
        virtual ~TopoStrategy() = default;
};

class Bfs_Topo: public TopoStrategy{
    vector<int>topoSort(vector<vector<int>>&adjList){
        int V = adjList.size();
        vector<int>inDegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adjList[i]){
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
        for(auto it:adjList[node]){
            inDegree[it]--;
            if(inDegree[it]==0) q.push(it);
        }
    }
    return topo;
    }
};

void dfs(vector<vector<int>>&list,vector<bool>&isVisited,int r,stack<int>&st){
    if(isVisited[r]) return;
    isVisited[r] = true;

    for(int i:list[r]){
        dfs(list,isVisited,i,st);
    }
    st.push(r);
}

class DFS_Topo:public TopoStrategy{
    public:
    vector<int> topoSort(vector<vector<int>>&adjList){
        int V = adjList.size();
        stack<int>st;
        vector<bool>isVisited(V,false);
        for(int i=00;i<V;i++){
        if(!isVisited[i]){
                dfs(adjList,isVisited,i,st);
            }
        }
        vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
    }
};

class TopoContext{
    private:
    TopoStrategy* topoStrategy;
    public:
    TopoContext(TopoStrategy* algorithm){
        this->topoStrategy = algorithm;
    }
    void setTopoStrategy(TopoStrategy* strategy){
        this->topoStrategy = strategy;
    }
    vector<int> performStrategy(vector<vector<int>>&adjList){
        if(topoStrategy){
            return topoStrategy->topoSort(adjList);
        }
    }
};

int main(){
      vector<vector<int>>edges =  {{1, 3}, {2, 3}, {4, 1},{4, 0}, {5, 0}, {5, 2}};
   int V = 6, E = 6;
   vector<vector<int>>adjancency_list(V);
    for(int i=0;i<E;i++){
        adjancency_list[edges[i][0]].push_back(edges[i][1]);
    }
    TopoContext dfsAlgo(new DFS_Topo());
    vector<int>ans = dfsAlgo.performStrategy(adjancency_list);
    for(auto it:ans){
        cout<<it<<" ";
    }
    
}