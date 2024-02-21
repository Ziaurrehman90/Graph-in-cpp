#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


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
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int extraEdge=0;
        for(auto &it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v)){
                extraEdge++;
                
            }
            else{
                ds.UniounByRank(u,v);
            }
        }
        // let's count the number of connected components 
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i){
                cnt++;
            }
        }
        int ans=cnt-1;
        if(extraEdge>=ans){
            return ans;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}