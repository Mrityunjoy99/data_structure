#include<bits/stdc++.h>
using namespace std;
class myHeap
{
    vector<int> v;
    int size;
    public: myHeap()
    {
        size=0;
    }
    public: void swap(int i,int j)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    
    private: int getLeftChiled(int index)
    {
        return index*2+1;
    }
    private: int getRightChiled(int index)
    {
        return index*2+2;
    }
    private: int getParent(int index)
    {
        return (index-1)/2;
    }
    private: void heapifyBottomUp(int index)
    {
        while(index)
        {
            if(v[index]>v[getParent(index)])
            {
                // cout<<"\t";
                // show();
                // printHeap();
                swap(index,getParent(index));
                // cout<<endl;
            }
            else
                break;
            index = getParent(index);
        }
        // printHeap();
    }
    
    
    private: void printSpace(int i)
    {
        while(i--)
            cout<<" ";
    }
    private: void heapifyTopDown(int index)
    {
        // printHeap();
        // cout<<endl;
        int left = getLeftChiled(index);
        int right = getRightChiled(index);
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
            swap(index,largest);
            heapifyTopDown(largest);
        }
    }
    public: void heapifyTopDown(int index,int size)
    {
        // printHeap();
        // cout<<endl;
        int left = getLeftChiled(index);
        int right = getRightChiled(index);
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
            swap(index,largest);
            heapifyTopDown(largest,size);
        }
    }
    public: void insert(int i)
    {
        v.push_back(i);
        size++;
        // cout<<"Inserting "<<i<<endl;
        heapifyBottomUp(v.size()-1);
        // cout<<i<<"\t";
        // show();

    }
    public: void pop()
    {
        swap(0,size-1);
        v.pop_back();
        size--;
        // cout<<"Popping ...."<<endl;
        heapifyTopDown(0);
        // show();
    }
    public: void show()
    {
        for(auto i:v)
            cout<<i<<" ";
        cout<<"\tsize : "<<size;
        cout<<endl;
    }
    public: void printHeap()
    {
        int height = log2(size)+1,spaceCt,index=0,upperBound;
        for(int h=height;h>0;h--)
        {
            spaceCt = h*(h+1)/2;
            upperBound = min((index+(int)pow(2,(height-h))),size);
            while(index<upperBound)
            {
                printSpace(spaceCt);
                cout<<v[index++];
                printSpace(spaceCt);
            }
            cout<<endl;
        }
    }
    public: void createHeapFromArr(vector<int> arr)
    {
        v = arr;
        size = arr.size();
        for(int i=size/2-1;i>=0;i--)
            heapifyTopDown(i);
    }
    public: vector<int> getArray()
    {
        return v;
    }
};

