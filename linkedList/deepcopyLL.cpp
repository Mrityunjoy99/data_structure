#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node *next;
        Node *random;
        Node(){}
        Node(int x)
        {
            val = x;
            next = random = NULL;
        }
};

Node* createLLFromArr(vector<vector<int>> &arr)
{
    Node *head = NULL, *temp, *newNode;
    vector<Node *> v;
    for(auto i:arr)
    {
        if(head==NULL)
        {
            head = new Node(i[0]);
            temp = head;
        }
        else
        {
            newNode = new Node(i[0]);
            temp->next = newNode;
            temp = newNode;
        }
        v.push_back(temp);
    }
    temp = head;
    for (int i = 0; i < arr.size(); i++)
    {
        temp->random = v[arr[i][1]];
        temp = temp->next;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp << "\t" << temp->val << "\t" << temp->random << "\t" << temp->random->val << endl;
        temp = temp->next;
    }
}

Node* deepClone(Node* head)
{
    Node *temp = head, *newHead, *newNode, *newTemp;
    newHead = new Node(head->val);
    newHead->next = head->next;
    head->next = newHead;
    temp = temp->next->next;
    while(temp!=NULL)
    {
        newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        newTemp = temp->next;
        newTemp->random = temp->random->next;
        temp = temp->next->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        newTemp = temp->next;
        temp->next = newTemp->next;
        temp = temp->next;
        newTemp->next = (temp!=NULL)?temp->next:NULL;
    }
    return newHead;
}

int main()
{
    vector<vector<int>> v = {
        {1, 4},
        {5, 0},
        {2, 3},
        {7, 1},
        {10, 2}};
    Node *head = createLLFromArr(v);
    printList(head);
    cout << endl
         << endl;
    Node *newHead = deepClone(head);
    printList(newHead);
}