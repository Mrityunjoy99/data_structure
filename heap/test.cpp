#include<bits/stdc++.h>
using namespace std;


string sum(string &s1,string &s2)
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

string solve(int arr[], int n) 
{
    vector<char> v;
    for(int i=0;i<n;i++)
        v.push_back('0'+arr[i]);
    priority_queue<char,vector<char>,greater<char>> pq(v.begin(),v.end());
    string s1 = "",s2 = "",s= "";
    char k;
    while(1)
    {
        if(!pq.empty())
        {
            k = pq.top();
            pq.pop();
            s1 += k;
        }
        else
            break;
        if(!pq.empty())
        {
            k = pq.top();
            pq.pop();
            s2 += k;
        }
        else
            break;
    }
    cout<<s1<<"\t"<<s2<<endl;
    s = sum(s1,s2);
    return s;
}

int main()
{
    int N = 7,Arr[] = {6, 8, 4, 5, 2, 3, 7};
    cout<<solve(Arr,N)<<endl;
}



