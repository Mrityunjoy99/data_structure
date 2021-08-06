#include<bits/stdc++.h>
using namespace std;

int recur(vector<int> &arr,int n,int index,int highest,vector<vector<int>> &dp)
{
    if(index>=n)
        return 0;
    if(dp[index][highest]!=-1)
        return dp[index][highest];
    
    dp[index][highest] = (arr[index]>arr[highest])?(max((recur(arr,n,index+1,index,dp)+arr[index]),recur(arr,n,index+1,highest,dp))):(recur(arr,n,index+1,highest,dp));
    return dp[index][highest];
}
int maxSumIS(int arr[], int n)  
{  
    vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < n;i++)
        v.push_back(arr[i]);
    int ans = recur(v, n+1, 0, 0, dp);
    for(auto i:dp)
    {
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return ans;
    // Your code goes here
}

int main()
{
    int n = 7;
    int arr[] = {20, 8, 27, 37, 9, 12, 46};
    cout << maxSumIS(arr, n) << endl;
}