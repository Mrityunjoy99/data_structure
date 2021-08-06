#include<bits/stdc++.h>
using namespace std;

int isValid(vector<int>& nums1, vector<int>& nums2,int k)
{
    int l1 = nums1.size(), l2 = nums2.size();
    int mid = (l1+l2)/2+(l1+l2)%2;
    int p1=k+1,p2=mid-p1;
    
    if((p2<l2)&&(p1>0)&&(p1<=l1)&&(p2>=0)&&(nums1[p1-1]>nums2[p2]))
        return 1;        
    else if((p1<l1)&&(p2>0)&&(p2<=l2)&&(p1>=0)&&(nums2[p2-1]>nums1[p1]))
        return -1;
    else
        return 0;
}
double findMidOfOneArr(vector<int> &v)
{
    int l = v.size();
    if(l%2==1)
        return v[l / 2];
    else
        return (double)(v[l / 2 - 1] + v[l / 2]) / 2;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()==0)
        return findMidOfOneArr(nums2);
    if(nums2.size()==0)
        return findMidOfOneArr(nums1);
    int l=0,r=nums1.size();
    int val=1,mid;
    while(val!=0)
    {
        mid=(l+r)/2;
        val=isValid(nums1,nums2,mid);
        if(val==1)
            r=mid;
        else if(val==-1)
            l=mid;
    }
    int m=nums1.size(),n=nums2.size();
    int curr_mid = (m + n) / 2 + (m + n) % 2;
    if((m+n)%2==1)
        return ((curr_mid-mid-2)>=0)?max(nums1[mid],nums2[curr_mid-mid-2]):nums1[mid];
    else
        return ((double)(((curr_mid-mid-2)>=0)?max(nums1[mid],nums2[curr_mid-mid-2]):nums1[mid])+(double)(((mid+1)<m)?min(nums1[mid+1],nums2[curr_mid-mid-1]):nums2[curr_mid-mid-1]))/2;
}

int main()
{
    vector<int> nums1 = {}, nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}