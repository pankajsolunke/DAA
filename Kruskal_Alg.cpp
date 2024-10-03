#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int u,v,weigth;
    Edge(int u,int v,int weigth) : u(u), v(v), weigth(weigth){}
};

int FindParent(int node,vector<int>&parent){
    if(parent[node] == node)
        return node;
    return parent[node] = FindParent(parent[node],parent);
}

void unionsets(int u,int v,vector<int>&parent,vector<int>rank){
    int parentU = FindParent(u,parent);
    int parentV = FindParent(v,parent);
    if(rank[parentU] > rank[parentV]){
        parent[parentV] = parentU;
    } else if(rank[parentU] < rank[parentV]){
        parent[parentU] = parentV;
    } else {
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}

bool compareEdges(Edge a, Edge b){
    return a.weigth < b.weigth;
}

void KruskalMST(int n,vector<Edge>&Edges){
    sort(Edges.begin(),Edges.end(),compareEdges);
    vector<Edge>mst;
    vector<int>parent(n);
    vector<int>rank(n,0);

    for(int i=0;i<n;++i){
        parent[i] = i;
    }
    int mstweigth = 0;
    for(int i = 0;i<Edges.size();i++){
        int u = Edges[i].u;
        int v = Edges[i].v;
        int parentU = FindParent(u,parent);
        int parentV = FindParent(v,parent);
        if(parentU != parentV){
            mst.push_back(Edges[i]);
            mstweigth += Edges[i].weigth;
            unionsets(parentU,parentV,parent,rank);
        }
    }

    cout<<"Edges in minimum - cost spanning tree\n";
    for(int i = 0;i<mst.size();i++){
        cout<<mst[i].u << "--"<<mst[i].v<<"=="<<mst[i].weigth<<"\n";
    }
    cout<<"Total weigth of mst: "<<mstweigth<<endl;
}

int main(){
    int n,e;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of Edges: ";
    cin>>e;
    vector<Edge>Edges;
    cout<<"Enter edges(Source,Destination,Weigth)";
    for(int i = 0;i<e;i++){
        int u,v,weigth;
        cout<<"Edges"<<(i + 1)<<": ";
        cin>>u>>v>>weigth;
        Edges.push_back(Edge(u,v,weigth));
    }
    KruskalMST(n,Edges);
    return 0;
}


