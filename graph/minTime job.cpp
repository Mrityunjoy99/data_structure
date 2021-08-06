#include<bits/stdc++.h>
using namespace std;
#define TUP tuple<int,int,int>

void minTime(vector<pair<int,int>> &edges,vector<int> &ans,int n)
{
    int time = 0, count=0;
    queue<int> q;
    vector<int> inEgde(n, 0);
    int from, to,index;
    vector<vector<int>> adj(n);
    for(auto edge:edges)
    {
        tie(from, to) = edge;
        adj[from].push_back(to);
        inEgde[to]++;
    }
    // for(int i:inEgde)
    //     cout << i << " ";
    // cout << endl;
    for (int i = 0; i < n;i++)
        if(inEgde[i]==0)
            q.push(i);
    while(!q.empty())
    {
        if(count==0)
        {
            count = q.size();
            time++;
        }
        index = q.front();
        q.pop();
        count--;
        ans[index] = time;
        for(int i:adj[index])
        {
            inEgde[i]--;
            if(inEgde[i]==0)
                q.push(i);
        }
    }
}

int main()
{
    int n = 7;
    vector<pair<int,int>> edges={
        {0,1},
        {1,2},
        {1,3},
        {1,4},
        {2,5},
        {3,5},
        {4,6}
    };

    vector<int> ans(n);
    minTime(edges, ans, n);
    
    for(int i:ans)
        cout << i << " ";
    cout << endl;
}