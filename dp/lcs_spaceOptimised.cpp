#include<bits/stdc++.h>
using namespace std;

int solve(string &s1,string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int b = 0;
    vector<vector<int>> dp(2, vector<int>(n+1));
    for (int i = 0; i <= m; i++)
    {
        b = i % 2;
        for (int j = 0; j <= n; j++)
        {
            if(i==0||j==0)
                dp[b][j] = 0;
            else if(s2[i-1]==s1[j-1])
                dp[b][j] = dp[1 - b][j - 1] + 1;
            else
            {
                dp[b][j] = max(dp[1 - b][j], dp[b][j - 1]);
            }
            
        }
    }
    return dp[m % 2][n];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GSTXAYB";
    if(s1.length()<s2.length())
        cout << solve(s1, s2) << endl;
    else
        cout << solve(s2, s1) << endl;
}