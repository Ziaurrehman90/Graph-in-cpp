#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
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
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1)
                ds.UniounByRank(i,j);
                
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i){
                count++;
            }
        }
        return count;
        
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}