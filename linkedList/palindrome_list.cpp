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

bool isPalindrome(Node *head)
{
    if(head==NULL)
        return true;
    int count=0;
    Node *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    int ct=0;
    stack<int> s;
    while(temp!=NULL)
    {
        ct++;
        if((count%2==1)&&(2*ct==count+1))
        {
            temp = temp->next;
            continue;
        }
        else if(2*ct>count)
        {
            if(temp->data==s.top())
                s.pop();
            else return false;
        }
        else
            s.push(temp->data);
        temp = temp->next;
    }
    return true;
    //Your code here
}

int main()
{
    int n=3;
    int arr[] = {1,2,1};
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n;i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << isPalindrome(head) << endl;
}