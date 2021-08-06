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
Node* createLLfromArray(vector<int> &arr,int index)
{
    Node *head=NULL, *temp, *newNode,*target;
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
            if(index!=-1&&i==arr[index])
                target = newNode;
            temp->next = newNode;
            temp = temp->next;
        }
    }
    if(index!=-1)
        temp->next = target;
    return head;
}
Node *detectCycle(Node *head) {
    Node *gar = new Node(0),*temp=head,*nxt;
    if(head==NULL)
        return NULL;
    while((temp->next!=gar)&&(temp->next!=NULL))
    {
        nxt = temp->next;
        temp->next = gar;
        temp = nxt;
    }
    if(temp->next==gar)
        return temp;
    else return NULL;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int index = 1;
    Node *head = createLLfromArray(v, index);
    Node *ans = detectCycle(head);
    if(ans!=NULL)
        cout << ans->val << endl;
    else
        cout << "Not found" << endl;
}