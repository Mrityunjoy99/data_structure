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

Node* splitCLL(Node* head)
{
    Node *fast = head, *slow = head, *ret;
    while(1)
    {
        if(fast==NULL)
        {
            // slow = slow->next;
            ret = slow->next;
            slow->next = NULL;
            return ret;
        }
        if(fast->next!=head)
        {
            fast = fast->next;
            if(fast->next!=head)
            {
                fast = fast->next;
                slow = slow->next;
            }
            else
            {
                fast->next = NULL;
                fast = NULL;
            }
        }
        else
        {
            fast->next = NULL;
            fast = NULL;
        }
        
        
        
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
    vector<int> v = {1, 2, 3, 4};
    Node *head = createLLfromArray(v, true);
    Node *head2 = splitCLL(head);
    printLL(head);
    printLL(head2);
}