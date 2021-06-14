#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<vector<int>> adj;
    bool directed;

    private:

    void dfsUtil(int index,vector<bool> &vis,vector<int> &dfsRes)
    {
        dfsRes.push_back(index);
        vis[index] = true;
        for(int i:adj[index])
        {
            if(!vis[i])
                dfsUtil(i,vis,dfsRes);
        }
    }

    public:
    Graph(int vertices,bool isDirected=false)
    {
        v = vertices;
        vector<int> vect;
        adj.resize(v);
        directed = isDirected;
    }

    void AddEdge(int from,int to)
    {
        adj[from].push_back(to);
        if(!directed)
            adj[to].push_back(from);
    }

    void bfs(int index)
    {
        queue<int> q;
        vector<bool> vis(v,false);
        q.push(index);
        vis[index] = true;
        int currIndex;
        cout<<"Output in BFS traversal : "<<endl;
        while(!q.empty())
        {
            currIndex = q.front();
            cout<<currIndex<<" ";
            q.pop();
            for(int i:adj[currIndex])
            {
                if(!vis[i])
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        cout<<endl;
    }

    void dfs(int index)
    {
        stack<int> s;
        vector<bool> vis(v,false);
        vector<int> dfsResult;
        dfsUtil(index,vis,dfsResult);

        cout<<"Output in DFS traversal : "<<endl;
        for(int i:dfsResult)
            cout<<i<<" ";
        cout<<endl;
    }
    void printAdjacent()
    {
        for(int i=0;i<adj.size();i++)
        {
            cout<<"Adjacent of "<<i<<" : ";
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }


};
