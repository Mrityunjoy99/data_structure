#include<bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
    return min(a, min(b, c));
}

int recurEditDistance(string s,string t,int i,int j,vector<vector<int>> &dp)
{
    if(i==s.length())
        return (t.length()-j);
    if(j==t.length())
        return (s.length() - i);
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    dp[i][j] = (s[i] == t[j]) ? (recurEditDistance(s, t, i + 1, j + 1, dp)) : (min(recurEditDistance(s, t, i + 1, j + 1, dp), recurEditDistance(s, t, i + 1, j, dp), recurEditDistance(s, t, i, j + 1, dp)) + 1);
    return dp[i][j];
}

int editSum(string s,string t)
{
    int l1 = s.length();
    int l2 = t.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
    return recurEditDistance(s, t, 0, 0, dp);
}

int main()
{
    string s = "geek", t = "gesek";
    cout << editSum(s, t) << endl;
}