#include<bits/stdc++.h>
using namespace std;

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
int main()
{
    string s1 = "123",s2 = "2567";
    cout<<sum(s1,s2)<<endl;
}




