#include <bits/stdc++.h>
using namespace std;

int max(int a,int b,int c)
{
    return max(max(a, b), c);
}

int recurLongestPalindromicSeq(string s,int i,int j,vector<vector<int>> &dp)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==s[j])
        dp[i][j] = max((recurLongestPalindromicSeq(s, i + 1, j - 1, dp) + ((i==j)?1:2)), (recurLongestPalindromicSeq(s, i + 1, j, dp)), (recurLongestPalindromicSeq(s, i, j - 1, dp)));
    else
        dp[i][j] = max(recurLongestPalindromicSeq(s, i + 1, j, dp), recurLongestPalindromicSeq(s, i, j - 1, dp));
    return dp[i][j];
}

int longestPalindromicSeq(string s)
{
    int i = 0, j = s.length() - 1;
    vector<vector<int>> dp(s.length() + 1,vector<int>(s.length()+1,-1));
    
    int ans = recurLongestPalindromicSeq(s,i,j,dp);
    // for(auto row:dp)
    // {
    //     for(int val:row)
    //         cout << val << " ";
    //     cout << endl;
    // }
    return ans;
}

int main()
{
    // string s = "GEEKSFORGEEKS";
    string s = "ABBCA";
    cout << longestPalindromicSeq(s) << endl;
}