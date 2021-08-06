#include<bits/stdc++.h>
using namespace std;

bool recurEquPart(int index,int sum,int n,int arr[],vector<vector<int>> &dp)
{
    if(index>=n)
        return false;
    if(sum==0)
        return true;
    
    if(dp[index][sum]!=-1)
        return (dp[index][sum]==1);
    
    dp[index][sum] = ((arr[index]<=sum)?(recurEquPart(index+1,sum-arr[index],n,arr,dp)||(recurEquPart(index+1,sum,n,arr,dp))):(recurEquPart(index+1,sum,n,arr,dp)))?1:0;
    return (dp[index][sum]==1);
}
int equalPartition(int N, int arr[])
{
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        sum+=arr[i];
    }
    if(sum%2==1)
        return 0;
    sum = sum/2;
    vector<vector<int>> dp(N+1,vector<int>(sum+1,-1));
    return recurEquPart(0,sum,N,arr,dp)?1:0;
}

int main()
{
    int N = 4, arr[] = {1, 5, 11, 5};
    int ans = equalPartition(N, arr);
    if(ans == 1)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}