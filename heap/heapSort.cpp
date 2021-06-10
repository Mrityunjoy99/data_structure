#include<bits/stdc++.h>
#include "heap.h"
using namespace std;

void HSort(vector<int> &arr)
{
    myHeap h;
    h.createHeapFromArr(arr);
    int size = arr.size();
    while(--size)
    {
        h.swap(0,size);
        h.heapifyTopDown(0,size);
    }
    arr = h.getArray();
}
int main()
{
    vector<int> arr = {2, 3, 5, 1, 9, 7};
    HSort(arr);
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
}