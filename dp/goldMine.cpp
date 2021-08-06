#include<bits/stdc++.h>
using namespace std;

int max(int a,int b,int c)
{
    return max(max(a,b),c);
}
int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>> dp(M.size()+1,vector<int>(M[0].size()+1,-1));
    int a,b,c;
    for(int i=0;i<n;i++)
        dp[i][0] = M[i][0];
        
    for(int j=1;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(i-1<0)
                a=0;
            else
                a=dp[i-1][j-1];
            
            b = dp[i][j-1];
            
            if(i+1>=n)
                c=0;
            else
                c=dp[i+1][j-1];
            
        dp[i][j] = max(a,b,c)+M[i][j];
        }
    }

    for(auto i:dp)
    {
        for(int j:i)
            cout << j << " ";
        cout << endl;
    }
    
    int ans=dp[0][m-1];
    for(int i=1;i<n;i++)
        ans = max(ans,dp[i][m-1]);
    return ans;
}

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> M = {{1, 3, 3},
                             {2, 1, 4},
                             {0, 6, 4}};

    cout << maxGold(n, m, M) << endl;
}
