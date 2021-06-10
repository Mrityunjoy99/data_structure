#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int myFunc(int i,int j,int x,int y,string s1,string s2,vector<vector<int>> &dp)
{
    if(i>=x||j>=y)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        if(s1[i]==s2[j])
        {
            dp[i][j] = 1 + myFunc(i+1,j+1,x,y,s1,s2,dp);
        }
        else
        {
            dp[i][j] = max(myFunc(i+1,j,x,y,s1,s2,dp),myFunc(i,j+1,x,y,s1,s2,dp));
        }
        return dp[i][j];
    }
}
void getEdge(int x,int y,int &i,int &j,vector<vector<int>> &dp)
{
    int n = dp[i][j];
    while(i<x&&dp[i][j]==n)
        i++;
    i--;
    while(j<y&&dp[i][j]==n)
        j++;
    j--;

}
void getSequence(vector<vector<int>> &dp,string s1,string s2)
{
    int i=0,j=0;
    queue<char> q;
    int n = dp[0][0];
    while(n--)
    {
        getEdge(s1.length(),s2.length(),i,j,dp);
        q.push(s1[i]);
        i++;j++;
    }

    cout<<"LCS : ";
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
    cout<<endl;

}
void printDpTable(vector<vector<int>> &dp,string s1,string s2)
{
    cout<<"dp table"<<endl<<"\t";
    for(auto i:s2)
        cout<<i<<"\t";
    cout<<endl;
    for(int i=0;i<s1.length();i++)
    {
        cout<<s1[i]<<"\t";
        for(int j=0;j<s2.length();j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
    myFunc(0,0,x,y,s1,s2,dp);
    printDpTable(dp,s1,s2);
    getSequence(dp,s1,s2);
    return dp[0][0];
    // your code here
}
int main()
{
    int x,y;
    string s1 = "ABCDGH",s2 = "AEDGFHR";
    x = s1.length();
    y = s2.length();
    cout<<lcs(x,y,s1,s2)<<endl;
}