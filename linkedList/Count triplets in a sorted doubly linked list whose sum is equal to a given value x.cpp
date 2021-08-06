#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
};
int countSubstr(Node *head,int sum)
{
    unordered_map<int, Node *> um;
    Node *temp = head;
    while(temp!=NULL)
    {
        um.insert({temp->data, temp});
        temp = temp->next;
    }
    int count = 0;
    for (Node *temp1 = head; temp1 != NULL;temp1=temp1->next)
    {
        for (Node *temp2 = temp1->next; temp2 != NULL;temp2=temp2->next)
        {
            if((um.find(sum-(temp1->data+temp2->data))!=um.end())&&(um[sum-(temp1->data+temp2->data)]!=temp1)&&(um[sum-(temp1->data+temp2->data)]!=temp2))
            {
                // cout << temp1->data << " " << temp2->data << " " << um[sum - (temp1->data + temp2->data)]->data << endl;
                count++;
            }
        }
    }
    return count/3;
}
int main()
{
    int n=7,sum=17;
    int arr[] = {1,2,4,5,6,8,9};
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n;i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    cout << countSubstr(head,sum) << endl;
}