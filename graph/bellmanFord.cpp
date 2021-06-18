#include<bits/stdc++.h>
using namespace std;
#define TUP tuple<int,int,int>
void bellmanFord(vector<TUP> edges,int n,int src)
{
    vector<int> weight(n, INT_MAX);
    weight[src] = 0;
    int from, to,cost;
    for (int i = 0; i < n - 1;i++)
    {
        for(auto edge:edges)
        {
            tie(from, to, cost) = edge;
            if(weight[from]!=INT_MAX&&(weight[from]+cost<weight[to]))
                weight[to] = weight[from] + cost;
        }
    }
    bool flag = false;
    for(auto edge:edges)
    {
        tie(from, to, cost) = edge;
        if(weight[from]!=INT_MAX&&(weight[from]+cost<weight[to]))
        {
            cout << "Negative weighted cycle detected " << endl;
            flag = true;
        }
    }
    if(!flag)
    {
        cout << "Minimum distance are : " << endl;
        for(auto i:weight)
            cout << i << " ";
        cout << endl;
    }
}

int main()
{
    int n = 6;
    vector<TUP> edges = {
        {0, 1, 2},
        {1, 2, -1},
        {0, 2, 4},
        {3, 1, -5},
        {2, 4, 3},
        {4, 3, 2},
        {3, 5, 1},
        {4, 5, 5}};
    bellmanFord(edges, n, 0);
}