#include<bits/stdc++.h>
using namespace std;
#define TUP tuple<int,int,int>

struct compareWeights
{
    bool operator()(const TUP &t1,const TUP &t2)
    {
        return get<2>(t1) > get<2>(t2);
    }
};
void primsAlgo(vector<vector<pair<int,int>>> &adj,int index)
{
    // cout << "hi";
    priority_queue<TUP, vector<TUP>, compareWeights> pq;
    unordered_set<int> inc;
    vector<TUP> sol;
    inc.insert(index);
    for(auto i:adj[index])
        pq.push({index, i.first, i.second});

    int from, to, wt, count = 1,n = adj.size();
    while(!pq.empty())
    {
        // cout << count << endl;
        if(count>n)
            break;
        tie(from, to, wt) = pq.top();
        pq.pop();
        if(inc.find(to)!=inc.end())
            continue;
        else
        {
            inc.insert(to);
            sol.push_back({from, to, wt});
            count++;
            for(auto i:adj[to])
                pq.push({to, i.first, i.second});
        }
    }

    for (int i = 0; i < sol.size();i++)
    {
        cout << get<0>(sol[i]) << " " << get<1>(sol[i]) << " " << get<2>(sol[i]) << endl;
    }
}

int main()
{
    int n = 11;
    vector<TUP> edges = {
        {0, 3, 3}, {3, 4, 3}, {4, 1, 3}, {0, 5, 1}, {5, 1, 100}, {0, 6, 2}, {6, 1, 100}, {0, 7, 1}, {7, 8, 1}, {8, 9, 1}, {9, 1, 1}, {1, 10, 1}, {10, 2, 1}, {1, 2, 100}};

    vector<vector<pair<int, int>>> adj(n);
    int from, to, wt;
    for(auto edge:edges)
    {
        tie(from, to, wt) = edge;
        adj[from].push_back({to, wt});
    }

    primsAlgo(adj, 0);
}