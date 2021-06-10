#include<bits/stdc++.h>
using namespace std;

void swap(int a[],int i,int j)
{
    int temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}
string sum(string s1,string s2)
{
    string s="";
    int i=s1.length()-1;
    int j=s2.length()-1;
    int sum,carry=0;
    while(i>=0&&j>=0)
    {
        sum = carry + (s1[i--]-'0') + (s2[j--]-'0');
        carry = sum/10;
        sum%=10;
        s += ('0'+sum);
    }
    while(i>=0)
    {
        sum = carry + (s1[i--]-'0');
        carry = sum/10;
        sum%=10;
        s += ('0'+sum);
    }
    while(j>=0)
    {
        sum = carry + (s2[j--]-'0');
        carry = sum/10;
        sum%=10;
        s += ('0'+sum);
    }

    while(carry!=0)
    {
        sum=carry;
        carry = sum/10;
        sum%=10;
        s += ('0'+sum);
    }
    while(s[s.length()-1]=='0')
        s.pop_back();
    reverse(s.begin(),s.end());
    return s;
}
void heapifyTopDown(int v[],int index,int size)
{
    // printHeap();
    // cout<<endl;
    int left = 2*index+1;
    int right = 2*index+2;
    int largest = index;
    if((left<size)&&(v[largest]<v[left]))
    {
        largest = left;
    }
    if((right<size)&&(v[largest]<v[right]))
    {
        largest = right;
    }
    if(index!=largest)
    {
        swap(v,index,largest);
        heapifyTopDown(v,largest,size);
    }
}

void createHeap(int arr[], int n)
{
    for(int i=n/2;i>=0;i--)
        heapifyTopDown(arr,i,n);
}


int top(int arr[])
{
    return arr[0];
}
void pop(int arr[],int &n)
{
    swap(arr,0,n-1);
    n--;
    heapifyTopDown(arr,0,n);
}
string solve(int arr[], int n) {
    // priority_queue<char,vector<char>,greater<char>> pq;
    string s1 = "",s2 = "",s= "";
    int k;
    createHeap(arr,n);
    while(1)
    {
        if(n>0)
        {
            k = top(arr);
            pop(arr,n);
            s1 += ('0'+k);
        }
        else
            break;
        if(n>0)
        {
            k = top(arr);
            pop(arr,n);
            s2 += ('0'+k);
        }
        else
            break;
    }
    // cout<<s1<<"\t"<<s2<<endl;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    s = sum(s1,s2);
    return s;
    
    // code here
}

int main()
{
    int N = 6,Arr[] = {6, 8, 4, 5, 2, 3};
    // cout<<"Hi";
    cout<<solve(Arr,N)<<endl;
}