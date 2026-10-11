#include <bits/stdc++.h>
using namespace std;


class TopoStrategy{
    public:
        virtual vector<int> topoSort(vector<vector<int>>&adjList)=0;
        virtual ~TopoStrategy() = default;
};

class Bfs_Topo: public TopoStrategy{
    public:
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
        return {};
    }
};




class AlienStrategy{
    public:
    virtual string getAlienLanguage(vector<string>&dict,int k)=0;
    virtual ~AlienStrategy() = default;
};


class BfsStrategy:public AlienStrategy{
    public:
    void createGraph(vector<vector<int>>&adj_list,string &s1,string &s2){
        int m = min(s1.size(),s2.size());
        for(int i=0;i<m;i++){
            int u = s1[i]-'a';
            int v = s2[i]-'a';
            if(u!=v){
                adj_list[u].push_back(v);
                break;
            }
        }
    }

    string getAlienLanguage(vector<string>&dict,int k){
        int dict_size = dict.size();
        vector<vector<int>>adj_list(k);
        for(int i=0;i<dict_size-1;i++){
            createGraph(adj_list,dict[i],dict[i+1]);
        }

        TopoContext topocontext(new Bfs_Topo());
        vector<int>topo = topocontext.performStrategy(adj_list);
        string ans = "";
        for(int it:topo){
            ans.push_back(it+'a');
        }
        if(topo.size()==k) return ans;
        return "";
    }
};

int main(){
    vector<string>dict = {"baa","abcd","abca","cab","cad"};
    int k = 4;

    AlienStrategy* alienstrategy;
    BfsStrategy bfsStrategy;
    alienstrategy = &bfsStrategy;
    cout<<alienstrategy->getAlienLanguage(dict,k);
}