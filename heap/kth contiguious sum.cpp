#include<bits/stdc++.h>
using namespace std;

int getKthHighestContiguiousSum(vector<int> v,int k)
{
    vector<int> subArratSum;
    int sum=0,count=0;
    subArratSum.push_back(sum);
    for(int i:v)
    {
        sum+=i;
        subArratSum.push_back(sum);
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<subArratSum.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(count<k)
            {
                pq.push(subArratSum[i]-subArratSum[j]);
                count++;
            }
            else
            {
                if(pq.top()<(subArratSum[i]-subArratSum[j]))
                {
                    pq.pop();
                    pq.push(subArratSum[i]-subArratSum[j]);
                }
            }
        }
    }
    return pq.top();

}

int main()
{
    vector<int> v = {20,-5,-1};
    int k = 3;
    cout<<getKthHighestContiguiousSum(v,k)<<endl;
}