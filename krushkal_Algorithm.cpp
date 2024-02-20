#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>parent;
    vector<int>rank;
    public:
    // constructor 
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    // lets make a function of find parents 
    int findUpar(int node){
        // base case
        if(node==parent[node]){
            return node;
        }
        // recursive case 
        return parent[node]=findUpar(parent[node]);
    }
    // here's the function of union 
    void UniounByRank(int u, int v){
        int up_u=findUpar(u);
        int up_v=findUpar(v);
        // if both have same parents then there is no need of the coonection 
        if(up_u==up_v){
            return;
        }
        // now let's check for the rank 
        // case1: 
        if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
            
        }
        // second case 
        else if(rank[up_v]<rank[up_u]){
            parent[up_v]=up_u;
        }
        // last case
        else{
            parent[up_v]=up_u;
            rank[up_u]++;
        }
    }


};

class Solution{
  public:
  int spanningTree(int V,vector<vector<int>>adj[]){
    vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int sum=0;
        for(auto &it:edges){
            int weight=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUpar(u)!=ds.findUpar(v)){
                sum+=weight;
                ds.UniounByRank(u,v);
            }
        }
        return sum;
        
    
  }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<vector<int>>adj[V];
        int i=0;
        while(i++<E){
            int u,v,w;
            cin>>u>>v>>w;
            vector<int>t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);


        }
        Solution obj;
        cout<<obj.spanningTree(V,adj)<<endl;
    }
    return 0;
}