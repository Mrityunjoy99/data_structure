#include<bits/stdc++.h>
using namespace std;

class myHeap
{
    vector<int> v;
    public:
        void swap(int i)
        {
            int temp = v[i];
            v[i] = v[(i-1)/2];
            v[(i-1)/2] = temp;
        }
        void heapyfy()
        {
            for(int i=v.size()-1;i>=0;i--)
            {
                if(v[i]>v[(i-1)/2])
                    swap(i);
            }
        }
        void heapyfyLast(int index)
        {
            while(index)
            {
                if(v[index]>v[(index-1)/2])
                {
                    cout<<"\t";
                    show();
                    swap(index);
                }
                else
                    break;
                index = (index-1)/2;
            }
        }
        void insert(int i)
        {
            v.push_back(i);
            heapyfyLast(v.size()-1);
            cout<<i<<"\t";
            show();

        }
        void show()
        {
            for(auto i:v)
                cout<<i<<" ";
            cout<<endl;
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
    // h.show();

}