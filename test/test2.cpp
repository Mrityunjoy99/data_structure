#include <bits/stdc++.h>
using namespace std;

string findOrder(vector<string> &dict, int N)
{
    vector<vector<int>> adj(N);
    int j;
    for (int i = 0; i < N; i++)
    {
        j = 0;
        while (j < (min(dict[i].length(), dict[i + 1].length())) && (dict[i][j] == dict[i + 1][j]))
        {
            j++;
        }
        adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
    }

    vector<int> indegree(N, 0);
    for (auto i : adj)
    {
        for (int k : i)
        {
            cout << k << " ";
            indegree[k]++;
        }
        cout << endl;
    }

    queue<int> q;
    string ans = "";
    for (int i = 0; i < N; i++)
    {
        cout << indegree[i] << " ";
        if (indegree[i] == 0)
            q.push(i);
    }
    cout << endl;
    int val;
    while (!q.empty())
    {
        val = q.front();
        q.pop();

        ans += ('a' + val);
        for (int i : adj[val])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return ans;
    // code here
}
int main()
{
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    cout << findOrder(words,4);
}