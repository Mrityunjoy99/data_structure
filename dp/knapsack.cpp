#include<bits/stdc++.h>
using namespace std;

int recurKnapSack(int index,int wt[],int val[],vector<vector<int>> &dp,int n,int w)
{
    if(index>=n)
        return 0;
    if(dp[index][w]!=-1)
        return dp[index][w];
    dp[index][w] = (wt[index] < w) ? (max((recurKnapSack(index + 1, wt, val, dp, n, w - wt[index]) + val[index]), recurKnapSack(index+1, wt, val, dp, n, w))) : recurKnapSack(index+1, wt, val, dp, n, w);
    return dp[index][w];
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    // for (int i = 0; i < n;i++)
    //     cout << wt[i] << " ";
    // cout << endl;
    return recurKnapSack(0, wt, val, dp, n, W);
}

int main()
{
    int N = 3, W = 4, values[] = {1, 2, 3}, weight[] = {4, 5, 6};
    cout << knapSack(W, weight, values, N) << endl;
}