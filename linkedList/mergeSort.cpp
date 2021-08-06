#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node *next;
        Node(){}
        Node(int x)
        {
            val = x;
            next = NULL;
        }
};
void printLL(Node *head);
Node* createLLfromArray(vector<int> &arr,bool isCircular)
{
    Node *head=NULL, *temp, *newNode;
    for(int i:arr)
    {
        if(head==NULL)
        {
            head = new Node(i);
            temp = head;
        }
        else
        {
            newNode = new Node(i);
            temp->next = newNode;
            temp = temp->next;
        }
    }
    if(isCircular)
        temp->next = head;
    return head;
}

Node* splitAtMiddle(Node *head)
{
    Node *fast = head, *slow = head;
    while(fast!=NULL)
    {
        if(fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        else
            fast = NULL;
    }
    Node *ret = slow->next;
    slow->next = NULL;
    return ret;
}

Node* mergeTwoSortedLL(Node* first,Node *second)
{
    Node *head = NULL;
    Node *temp;

    if(first->val<second->val)
    {
        head = first;
        first = first->next;
    }
    else
    {
        head = second;
        second = second->next;
    }
    temp = head;
    while(first!=NULL&&second!=NULL)
    {
        if(first->val<second->val)
        {
            temp->next = first;
            first = first->next;
        }
        else
        {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }
    if(first!=NULL)
        temp->next = first;
    if(second!=NULL)
        temp->next = second;
    return head;
}

Node* mergeSort(Node *head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    else
    {
        Node *mid = splitAtMiddle(head);
        Node *first = mergeSort(head);
        Node *second = mergeSort(mid);
        return mergeTwoSortedLL(first, second);
    }
}

void printLL(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> v{1, 5, 2, 7, 8, 4, 6, 3, 4};
    Node *head = createLLfromArray(v, false);
    printLL(head);
    head = mergeSort(head);
    printLL(head);

    
}