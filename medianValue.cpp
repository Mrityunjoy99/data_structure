#include<bits/stdc++.h>
using namespace std;

double meanValue(priority_queue<int> mxHeap,priority_queue<int,vector<int>,greater<int>> mnHeap)
{
    if(mxHeap.size()==mnHeap.size()&&mxHeap.size()!=0)
        return (double)(mxHeap.top()+mnHeap.top())/2;
    else if(mxHeap.size()>mnHeap.size())
        return mxHeap.top();
    else if(mxHeap.size()<mnHeap.size())
        return mnHeap.top();
    else return 0;

}

double getMean(vector<int> v,int k)
{
    priority_queue<int> mxHeap;
    priority_queue<int,vector<int>,greater<int>> mnHeap;
    int lenOfMx ,lenOfMn;
    double avgVal;
    for(int i=0;i<k;i++)
    {
        lenOfMx = mxHeap.size();
        lenOfMn = mnHeap.size();
        // cout<<lenOfMx<<"\t"<<lenOfMn<<endl;
        avgVal = meanValue(mxHeap,mnHeap);
        // cout<<"AvgValue : "<<avgVal<<endl;
        if(v[i]>avgVal)
        {
            if(lenOfMn>lenOfMx)
            {
                mxHeap.push(mnHeap.top());
                // cout<<mnHeap.top()<<" placed at max Heap"<<endl;
                mnHeap.pop();
            }
            mnHeap.push(v[i]);
            // cout<<v[i]<<" placed at min Heap"<<endl;
        }
        else
        {
            if(lenOfMx>lenOfMn)
            {
                mnHeap.push(mxHeap.top());
                // cout<<mxHeap.top()<<" placed at min Heap"<<endl;
                mxHeap.pop();
            }
            mxHeap.push(v[i]);
            // cout<<v[i]<<" placed at max Heap"<<endl;
        }
    }
    
    double ans = meanValue(mxHeap,mnHeap);
    return ans;
}

int main()
{
    vector<int> v = {5,10,15};
    for(int i=1;i<=v.size();i++)
        cout<<getMean(v,i)<<endl;
}
