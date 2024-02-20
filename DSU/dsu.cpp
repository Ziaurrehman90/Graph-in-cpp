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
int main(){
    // initialization 
    DisjointSet ds(7);
    ds.UniounByRank(1,2);
    ds.UniounByRank(2,3);
    ds.UniounByRank(4,5);
    ds.UniounByRank(6,7);
    ds.UniounByRank(5,6);
    // check the parent of the node 
    cout<<"before connecting :"<<endl;
    if(ds.findUpar(3)==ds.findUpar(7)){
        cout<<"Both have same ultimate Parents\n";
    }
    else{
        cout<<"Both have different ultimate Parents!\n";
    }
    ds.UniounByRank(3,7);
    cout<<"after connecting : "<<endl;
    if(ds.findUpar(3)==ds.findUpar(7)){
        cout<<"Both have same ultimate Parents";
    }
    else{
        cout<<"Both have different ultimate Parents!";
    }

    return 0;

}