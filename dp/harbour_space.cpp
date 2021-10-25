#include<bits/stdc++.h>
using namespace std;

int helper(string s,unordered_set<int> us,int i)
{
    // if(j>=s.length())
    //     return 0;
    int j;
    while(us.find(i)!=us.end())
        i++;
    if((i+2)<j)
    {
        j = i + 2;
        j %= (s.length());
    }
    while(us.find(j)!=us.end())
    {
        j++;
        j %= (s.length());
    }
    if(i>=(s.length()-1))
        return 0;
    
    if(s[i]==s[j])
        return helper(s, us, i + 1);
    else
    {
        unordered_set<int> us1 = us;
        us.insert(i);
        us1.insert(j);
        return 1 + min(helper(s, us, i + 1), helper(s, us1, i));
    }
}

void solve()
{
    string s;
    cin >> s;
    unordered_set<int> us;
    cout << helper(s, us, 0) << endl;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        solve();
    }
}