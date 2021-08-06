#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
        
    vector<int> sum(n);
    sum[0]=arr[0];
    for(int i=1;i<n;i++)
        sum[i] = sum[i-1]+arr[i];

    cout << "Subarray sum : " << endl;
    for(auto i:sum)
        cout << i << " ";
    cout << endl;
    int low = min(0,arr[0]),high=sum[0];
    int mx=arr[0];
    for(int i=1;i<sum.size();i++)
    {
        if(sum[i]>high)
        {
            high = sum[i];
            // highInd = i;
            if(low<0)
                mx = max(mx,high-low);
            else
                mx = max(mx,high);
        }
        if(sum[i]<low)
        {
            low = sum[i];
            high = INT_MIN;
        }
        
    }
    return mx;
    
}

int main(int argc, char const *argv[])
{
    // int n = 14;
    // int arr[] = {74, -72, 94, -53, -59, -3, -66, 36, -13, 22, 73, 15, -52, 75};

    int n = 8;
    int arr[] = {-47, 43, 94, -94, -93, -59, 31, -86};
    cout << maxSubarraySum(arr, n) << endl;
    return 0;
}
