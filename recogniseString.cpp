#include<bits/stdc++.h>
using namespace std;

struct node
{
    char ch;
    int val;
};
struct compareValue
{
    bool operator()(node const &n1,node const & n2)
    {
        return n1.val<n2.val;
    }
};

string reorganizeString(string s) 
{
    unordered_map<char,int> m;
    for(int i=0;i<s.length();i++)
    {
        if(m.find(s[i])==m.end())
            m[s[i]]=1;
        else
            m[s[i]]++;
    }
    node n;
    priority_queue<node,vector<node>,compareValue> pq;
    for(auto i : m)
    {
        n.ch = i.first;
        n.val = i.second;
        // cout<<n.ch<<"\t"<<n.val<<endl;
        pq.push(n);
    }
    string ans;
    node temp;
    n=pq.top();
    pq.pop();
    ans += n.ch;
    // cout<<ans<<endl;
    n.val--;
    temp=n;
    while(!pq.empty())
    {
        n=pq.top();
        pq.pop();
        ans += n.ch;
        n.val--;
        if(temp.val>0)
            pq.push(temp);
        temp=n;        
    }
    if(s.length()==ans.length())
        return ans;
    else return "";
}

int main()
{
    string s = "aab";
    cout<<reorganizeString(s)<<endl;
}

