#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str){
    int l = str.length();
    vector<vector<int>> dp(l+1,vector<int>(l+1,-1));
    int mx = 0;
    dp[0][0] = 0;
    bool flag = false;
    for(int i=1;i<l;i++)
    {
        if(str[0]==str[i])
            flag = true;
        if(flag)
        {
            dp[0][i]=1;
            dp[i][0]=1;
        }
        else
        {
            dp[0][i]=0;
            dp[i][0]=0;
        }
    }
    
    for(int i=1;i<l;i++)
    {
        for(int j=1;j<l;j++)
        {
            if((i!=j)&&(str[i]==str[j]))
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    for (int i = 0; i < l;i++)
    {
        for (int j = 0; j < l;j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

        return dp[l - 1][l - 1];
    // Code here
}

int main()
{
    string s = "yvpyruvjhb";
    cout << LongestRepeatingSubsequence(s) << endl;
}