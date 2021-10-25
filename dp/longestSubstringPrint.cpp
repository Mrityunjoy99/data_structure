#include <bits/stdc++.h>
using namespace std;

int helper(string s, int i, int j, string &ans, vector<vector<int>> &dp)
{
    if (i >= j)
        return 1;
    if (dp[i][j] != 0)
        return dp[i][j];
    if (s[i] == s[j])
    {
        dp[i][j] = helper(s, i + 1, j - 1, ans, dp);
        if (dp[i][j] == 1)
        {
            if ((j - i + 1) > (ans.length()))
            {
                ans = s.substr(i, (j - i + 1));
            }
            else
            {
                cout << "i : " << i << "\tj : " << j << "\t diff = " << (j - i) << "\tlength : " << ans.length() << endl;
            }
        }
    }
    else
        dp[i][j] = -1;
    helper(s, i + 1, j, ans, dp);
    helper(s, i, j - 1, ans, dp);
    return dp[i][j];
}
string longestPalindrome(string s)
{
    int l = s.length();
    vector<vector<int>> dp(l + 1, vector<int>(l + 1, 0));
    string ans = "";
    helper(s, 0, l - 1, ans, dp);
    return ans;
    // code here
}

int main()
{
    string s = "aaaabbaa";
    cout << longestPalindrome(s) << endl;
}