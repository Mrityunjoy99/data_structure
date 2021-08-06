#include<bits/stdc++.h>
using namespace std;

void recurFuncForPath(vector<int> &arr,int n,int index,vector<vector<int>> &ans,vector<int> temp)
{
    if(n==0)
    {
        ans.push_back(temp);
        return;
    }
    if(index>=arr.size())
        return;
    if(arr[index]<=n)
    {
        recurFuncForPath(arr, n, index + 1, ans, temp);
        temp.push_back(arr[index]);
        recurFuncForPath(arr, n - arr[index], index, ans, temp);
    }
    else
    {
        recurFuncForPath(arr, n, index + 1, ans, temp);
    }
}

void findPath(vector<int> &arr,int n)
{
    vector<int> temp;
    vector<vector<int>> ans;
    recurFuncForPath(arr, n, 0, ans, temp);
    for(auto i:ans)
    {
        for(int j:i)
            cout << j << " ";
        cout << endl;
    }
}

int recurFuncForCount(vector<int> &arr,int n,int index,vector<vector<int>> &dp)
{
    if(n==0)
        return 1;
    if(index>=arr.size())
        return 0;
    if(dp[n][index]!=-1)
        return dp[n][index];
    dp[n][index] = (arr[index] <= n) ? (recurFuncForCount(arr, n - arr[index], index, dp)+ recurFuncForCount(arr, n, index + 1, dp)) : recurFuncForCount(arr, n, index + 1, dp);
    return dp[n][index];
}

int countPossiblePath(vector<int> &arr,int n)
{
    vector<vector<int>> dp(n+1, vector<int>(arr.size()+1, -1));
    return recurFuncForCount(arr, n, 0, dp);
}

int recurFindMin(vector<int> &arr,int n,int index,vector<vector<int>> &dp)
{
    if(n==0)
        return 0;
    if(index>=arr.size())
        return 9999;
    if(dp[n][index]!=-1)
        return dp[n][index];
    dp[n][index] = (arr[index] <= n) ? (min((recurFindMin(arr, n - arr[index], index, dp)+1), recurFindMin(arr, n, index + 1, dp))) : (recurFindMin(arr, n, index + 1, dp));
    return dp[n][index];
}
int findMin(vector<int> &arr,int n)
{
    vector<vector<int>> dp(n+1, vector<int>(arr.size()+1, -1));
    return recurFindMin(arr, n, 0, dp);
}

int main()
{
    int n = 7;
    vector<int> arr = {1, 2, 3};
    findPath(arr, n);
    cout << "Possible path count : " << countPossiblePath(arr, n) << endl;
    cout << "Minimum possible path length : " << findMin(arr, n) << endl;
}