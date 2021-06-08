#include<bits/stdc++.h>
using namespace std;

int getMinPos(vector<int> v)
{
    int minPos = 0;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<v[minPos])
            minPos=i;
    }
    return minPos;
}
vector<int> getKLargestElements(vector<int> v,int k)
{
    priority_queue <int, vector<int>, greater<int> > pq;
    vector<int> temp;
    for(int i=0;i<k;i++)
    {
        pq.push(v[i]);
    }
    for(int i=k;i<v.size();i++)
    {
        if(v[i]>pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
    while(!pq.empty())
    {
        temp.push_back(pq.top());
        pq.pop();
    }
    return temp;
}
int main()
{
    vector<int> arr = {2,4,5,3,6,9,1};
    arr = getKLargestElements(arr,4);
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
}