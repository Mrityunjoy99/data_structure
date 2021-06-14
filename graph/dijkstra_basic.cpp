#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int index,val;
    Node(){}
    Node(int i,int v)
    {
        index = i;
        val = v;
    }
    void setVal(int i,int v)
    {
        index = i;
        val = v;
    }
};

struct Edge
{
    int index,cost;
    Edge()
    {

    }
    Edge(int i,int c)
    {
        index = i;
        cost = c;
    }
    void setVal(int i,int c)
    {
        index = i;//index of to
        cost = c;//cost of edge
    }
};

struct compareValue
{
    bool operator()(Node &n1,Node &n2)
    {
        return n1.val>n2.val;
    }
};
void dijkstra(vector<vector<Edge>> &adj,vector<int> &val,int index)
{
    priority_queue<Node,vector<Node>,compareValue> pq;
    vector<bool> vis(adj.size());
    Node n;
    val[index] = 0;
    n.setVal(index,val[index]);
    pq.push(n);

    while(!pq.empty())
    {
        n = pq.top();
        pq.pop();
        vis[n.index] = true;
        for(auto i : adj[n.index])
        {
            val[i.index] = min(val[i.index],i.cost+val[n.index]);
            if(!vis[i.index])
            {
                n.setVal(i.index,val[i.index]);
                pq.push(n);
            }
        }
    }
    cout<<"set of values are : "<<endl;
        for(int i:val)
        cout<<i<<"\t";
    cout<<endl;
}

vector<int> dijkstraForMindistance(vector<vector<Edge>> &adj,vector<int> &val,int start,int end)
{
    priority_queue<Node,vector<Node>,compareValue> pq;
    vector<int> preIndex(adj.size(),-1);
    vector<bool> vis(adj.size());
    Node n;
    val[start] = 0;
    n.setVal(start,val[start]);
    pq.push(n);
    vector<int> path;
    int preI;
    
    while(!pq.empty())
    {
        n = pq.top();
        pq.pop();
        vis[n.index] = true;
        if(n.index==end)
        {
            preI = n.index;
            while(preI!=-1)
            {
                path.push_back(preI);
                preI = preIndex[preI];
            }
            reverse(path.begin(),path.end());
            return path;
            //return the vector<>
        }
        for(auto i : adj[n.index])
        {
            if(val[i.index]>i.cost+val[n.index])
            {
                val[i.index]=i.cost+val[n.index];
                preIndex[i.index] = n.index;
            }
            if(!vis[i.index])
            {
                n.setVal(i.index,val[i.index]);
                cout<<"pushing : "<<i.index<<" with value "<<val[i.index]<<endl;
                pq.push(n);
            }
        }
    }
    cout<<"set of values are : "<<endl;
        for(int i:val)
        cout<<i<<"\t";
    cout<<endl;
}

int main()
{
    int N = 11;
    vector<vector<int>> edge = {
        // {0,1,2},
        // {1,2,1},
        // {0,2,4},
        // {1,3,7},
        // {2,4,3},
        // {4,3,2},
        // {3,5,1},
        // {4,5,5}
        {0,3,3},{3,4,3},{4,1,3},{0,5,1},{5,1,100},{0,6,2},{6,1,100},{0,7,1},{7,8,1},{8,9,1},{9,1,1},{1,10,1},{10,2,1},{1,2,100}
    };
    vector<vector<Edge>> adj(N);
    Edge e;
    for(auto i:edge)
    {
        e.setVal(i[1],i[2]);
        adj[i[0]].push_back(e);
    }
    vector<int> val(adj.size(),INT_MAX);
    // dijkstra(adj,val,0);
    int start = 0,end = 2;
    vector<int> path = dijkstraForMindistance(adj,val,start,end);
    cout<<"Path from "<<start<<" to "<<end<<" : "<<endl;
    for(int i: path)
        cout<<i<<"\t";
    cout<<endl;

}