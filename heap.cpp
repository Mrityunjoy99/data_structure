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
    private: void swap(int i,int j)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    private: void heapyfyBottomUp(int index)
    {
        while(index)
        {
            if(v[index]>v[getParent(index)])
            {
                // cout<<"\t";
                // show();
                printHeap();
                swap(index,getParent(index));
                cout<<endl;
            }
            else
                break;
            index = getParent(index);
        }
        printHeap();
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
    private: void heapyfyTopDown(int index)
    {
        printHeap();
        cout<<endl;
        int left = getLeftChiled(index);
        int right = getRightChiled(index);
        
        if((left<size)&&(v[index]<v[left]))
        {
            swap(index,left);
            if((right<size)&&(v[index]<v[right]))
            {
                swap(index,right);
                heapyfyTopDown(right);
            }
            heapyfyTopDown(left);
        }
        else if((right<size)&&(v[index]<v[right]))
        {
            swap(index,right);
            heapyfyTopDown(right);
        }
        else return;
    }
    private: void printSpace(int i)
    {
        while(i--)
            cout<<" ";
    }
    public: void insert(int i)
    {
        v.push_back(i);
        size++;
        cout<<"Inserting "<<i<<endl;
        heapyfyBottomUp(v.size()-1);
        // cout<<i<<"\t";
        // show();

    }
    public: void pop()
    {
        swap(0,size-1);
        v.pop_back();
        size--;
        cout<<"Popping ...."<<endl;
        heapyfyTopDown(0);
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
};

int main()
{
    myHeap h;
    h.insert(2);
    h.insert(4);
    h.insert(3);
    h.insert(1);
    h.insert(5);
    h.pop();
    h.insert(9);
    h.pop();
    h.pop();
    h.insert(5);
    // h.printHeap();
    // h.show();

}