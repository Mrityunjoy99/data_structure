#include<bits/stdc++.h>
using namespace std;

int max(int a,int b,int c)
{
    return max(a,max(b,c));
}
int longestSubsequence(int n, int a[])
{
    vector<int> dp(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((a[i]>a[j])&&(dp[i]<dp[j]+1))
                dp[i] = dp[j]+1;
        }
    }
    int ans = dp[0];
    for(int i:dp)
    {
        cout<<i<<"\t";
        ans = max(ans,i);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
    return ans;

}

int main()
{
    int n = 16, a[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    // int n = 6, a[] = {5,8,3,7,9,1};
    cout<<"\n\nAns : "<<longestSubsequence(n,a)<<endl;
}