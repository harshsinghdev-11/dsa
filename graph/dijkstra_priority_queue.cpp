#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int S,vector<vector<int>>adjList[],int V){
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> >pq;
    vector<int>dist(V,1e9);
    dist[S]=0;
    pq.push({0,S});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:adjList[node]){
            int edge_weight = it[1];
            int adj_node = it[0];
            if(dis+edge_weight<dist[adj_node]){
                dist[adj_node]=dis+edge_weight;
                pq.push({dist[adj_node],adj_node});
            }
        }
    }
    return dist;
}

int main(){
    int V=5;
    vector<vector<int>>adjList[V];
     adjList[0].push_back({1, 2});
    adjList[0].push_back({2, 4});

    adjList[1].push_back({2, 1});
    adjList[1].push_back({3, 7});

    adjList[2].push_back({4, 3});

    adjList[3].push_back({4, 1});
    int S=0;
    vector<int> dist = dijkstra(S, adjList, V);

    for (int i = 0; i < V; i++) {
        cout << "Distance from " << S
             << " to " << i << " = ";

        if (dist[i] == 1e9)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;

}