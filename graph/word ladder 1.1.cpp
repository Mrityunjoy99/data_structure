#include<bits/stdc++.h>
using namespace std;
#define TUP tuple<int,int>
bool compareString(string s1,string s2)
{
    int count = 0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[i])
            count++;
    }
    return count==1;
}

int bfs(vector<vector<int>> &adj,int src,int dest)
{
    queue<TUP> q;
    vector<int> par(adj.size(), -1);
    vector<bool> vis(adj.size(),false);
    int index,depth,temp;
    q.push({src,0});
    while(!q.empty())
    {
        tie(index,depth) = q.front();
        q.pop();
        vis[index] = true;
        if(index==dest)
        {
            temp = dest;
            while(temp!=-1)
            {
                cout << temp << "\t";
                temp = par[temp];
            }
            return depth;
        }
        
        for(auto i:adj[index])
        {
            if(!vis[i])
            {
                q.push({i,depth+1});
                par[i] = index;
            }
        }
    }
    
    return 0;
    
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int src=-1,dest;
    for(int i=0;i<wordList.size();i++)
    {
        if(wordList[i]==beginWord)
            src = i;
        if(wordList[i]==endWord)
            dest = i;
    }
    // cout << src << " " << dest;
    if(src==-1)
    {
        wordList.push_back(beginWord);
        src = wordList.size()-1;
    }
    vector<vector<int>> adj(wordList.size());
    for(int i=0;i<wordList.size();i++)
    {
        for(int j=i+1;j<wordList.size();j++)
        {
            if(compareString(wordList[i],wordList[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=0;i<wordList.size();i++)
    {
        if(wordList[i]==beginWord)
            src = i;
        if(wordList[i]==endWord)
            dest = i;
    }
    cout << "Adj list : " << endl;
    for (int i = 0; i < adj.size();i++)
    {
        cout << i << " : ";
        for(auto j:adj[i])
            cout << j << " ";
        cout << endl;
    }

    return bfs(adj,src,dest);
}

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string startWord = "hit", endWord = "cog";
    cout<<"ans = "<<ladderLength(startWord, endWord, wordList);
}