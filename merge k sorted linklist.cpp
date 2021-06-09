#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct compareValue
{
    bool operator()(Node* const n1,Node* const n2)
    {
        return n1->data>n2->data;
    }
};
Node * mergeKLists(Node *arr[], int K)
{
    int k=K;
    unordered_map<Node*,int> um;
    priority_queue<Node*,vector<Node*>,compareValue> pq;

    for(int i=0;i<k;i++)
    {
        um.insert({arr[i],i});
        pq.push(arr[i]);
        arr[i] = arr[i]->next;
    }

    Node *head = pq.top();
    Node *temp = head,*n = head;
    int index = um[n];
    um.erase(n);
    pq.push(arr[index]);
    um.insert({arr[index],index});
    while(!pq.empty())
    {
        n = pq.top();
        pq.pop();
        temp->next=n;
        temp=n;
        int index = um[n];
        um.erase(n);
        pq.push(arr[index]);
        um.insert({arr[index],index});
    }
    
    return head;

}

int main()
{
    
}