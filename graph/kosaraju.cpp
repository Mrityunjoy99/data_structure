#include<bits/stdc++.h>
using namespace std;
#define TUP tuple<int,int,int>

void createStack(vector<vector<int>> &adj, stack<int> &s, vector<bool> &vis,int index)
{
    vis[index] = true;
    for(int i:adj[index])
    {
        if(!vis[i])
            createStack(adj, s, vis, i);
    }
    s.push(index);
}

void reverseGraph(vector<vector<int>> &adj,vector<vector<int>> &revadj)
{
    for (int i = 0; i < adj.size();i++)
    {
        for(int j:adj[i])
            revadj[j].push_back(i);
    }
}
void ConnectedComponents(vector<vector<int>> &adj,int index,vector<int> &temp,vector<bool> &vis)
{
    temp.push_back(index);
    vis[index] = true;
    for(int i:adj[index])
    {
        if(!vis[i])
            ConnectedComponents(adj, i, temp, vis);
    }
}
vector<vector<int>> kosaraju(vector<vector<int>> &adj)
{
    stack<int> s;
    vector<bool> vis(adj.size(), false);
    for (int i = 0; i < adj.size();i++)
    {
        if(!vis[i])
            createStack(adj, s, vis, i);
    }

    vector<vector<int>> revadj(adj.size());
    reverseGraph(adj, revadj);
    vector<vector<int>> ans;
    vector<int> temp;
    vis.clear();
    vis.assign(adj.size(),false);
    int index;
    while(!s.empty())
    {
        index = s.top();
        s.pop();
        temp.clear();
        if(!vis[index])
        {
            ConnectedComponents(revadj, index, temp, vis);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<pair<int, int>> graph = {{0, 2},
                                    {0, 3},
                                    {3, 1},
                                    {4, 1},
                                    {5, 0},
                                    {1, 0} };

    vector<vector<int>> adj(n);
    for(auto edge:graph)
    {
        adj[edge.first].push_back(edge.second);
    }

    vector<vector<int>> ans = kosaraju(adj);
    for (int i = 0; i < ans.size();i++)
    {
        for(int j:ans[i])
            cout << j << " ";
        cout << endl;
    }
}