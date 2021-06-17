#include<bits/stdc++.h>
using namespace std;

int find(vector<int> parent,int i)
{
    if(parent[i]==-1)
        return i;
    else
        return find(parent, parent[i]);
}

bool detectCycle(vector<pair<int, int>> &edges,int n)
{
    vector<int> parent(n,-1);
    int from, to,fromP,toP;

    for(auto edge:edges)
    {
        tie(from, to) = edge;
        fromP = find(parent, from);
        toP = find(parent, to);

        if(fromP == toP)
            return true;
        else
        {
            parent[fromP] = toP;
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
                                    {5, 0}};

    cout << detectCycle(graph, n) << endl;
}