#include<bits/stdc++.h>
using namespace std;

enum Color
{
    WHITE,
    GREY,
    BLACK
};

bool DFSUtil(vector<vector<int>> &adj,vector<int> &color,int index)
{
    color[index] = GREY;
    for(int i:adj[index])
    {
        if(color[i]==GREY)
            return true;
        else if(color[i]==WHITE&&DFSUtil(adj, color, i))
            return true;
    }
    color[index] = BLACK;
    return false;
}

bool isCyclicDirected(vector<vector<int>> &adj)
{
    vector<int> color(adj.size(), WHITE);
    bool ans=false;
    for (int i = 0; i < adj.size();i++)
    {
        if(color[i]==WHITE&&DFSUtil(adj, color, i))
        {
            return true;
        }
    }
    return false;
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
    cout<<isCyclicDirected(adj);
}