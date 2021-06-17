#include <bits/stdc++.h>
using namespace std;

void DFSUtil(vector<vector<int>> &adj, int index, stack<int> &s, vector<bool> &vis)
{
    vis[index] = true;
    for (auto i : adj[index])
    {
        if (!vis[i])
        {
            DFSUtil(adj, i, s, vis);
        }
    }
    s.push(index);
}

void topologicalSort(vector<vector<int>> &adj)
{
    stack<int> s;
    vector<bool> vis(adj.size(), false);
    for (int i = 0; i < adj.size(); i++)
    {
        if (!vis[i])
            DFSUtil(adj, i, s, vis);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int n = 6;
    vector<pair<int, int>> graph = {{0, 2},
                                    {0, 3},
                                    {3, 1},
                                    {4, 1},
                                    {4, 2},
                                    {5, 0},
                                    {5, 2}};

    vector<vector<int>> adj(n);
    int start, end;
    for (auto i : graph)
    {
        tie(start, end) = i;
        adj[start].push_back(end);
    }

    topologicalSort(adj);
}