#include<bits/stdc++.h>
using namespace std;
#define TUP tuple<int,int,int>

struct compareTuple
{
    bool operator()(const TUP &t1,const TUP &t2)
    {
        return get<1>(t1)>get<1>(t2);
    }
};

int findCheapestPrice(int N, vector<vector<int>>& flights, int src, int dst, int k)
{
    vector<vector<pair<int,int>>> adj(N);
    vector<int> finalValue(N, INT_MAX);
    for(auto i:flights)
    {
        adj[i[0]].push_back({i[1],i[2]});
    }
    
    int index,nodeValue,depth,to,transaction_cost;

    priority_queue<TUP,vector<TUP>,compareTuple> pq;
    // queue<TUP> pq;

    pq.push({src,0,0});
    while(!pq.empty())
    {
        tie(index,nodeValue,depth) = pq.top();
        pq.pop();
        // cout << index<<" "<<nodeValue<<" "<<depth<<endl;
        // finalValue[index] = min(finalValue[index], nodeValue);
        if(index==dst)
            return nodeValue;
        if(depth>k)
            continue;
        
        for(auto i:adj[index])
        {
            tie(to, transaction_cost) = i;
            pq.push({to, nodeValue + transaction_cost, depth + 1});
            // if(finalValue[to]>nodeValue+transaction_cost)
            // {
            //     pq.push({to, nodeValue + transaction_cost, depth + 1});
            // }
        }
    }
    // return finalValue[dst] == INT_MAX ? -1 : finalValue[dst];
    return -1;
}

int main()
{
    int N = 11;
    int src = 0;
    int dest = 2;
    int k = 4;

    vector<vector<int>> edge = {
        {0,3,3},{3,4,3},{4,1,3},{0,5,1},{5,1,100},{0,6,2},{6,1,100},{0,7,1},{7,8,1},{8,9,1},{9,1,1},{1,10,1},{10,2,1},{1,2,100}
    };

    cout<<findCheapestPrice(N,edge,src,dest,k)<<endl;
}