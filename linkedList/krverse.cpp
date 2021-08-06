#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        next = NULL;
    }
};
struct node * helper(struct node* head,int k,node* &nextHead)
{
    node *prev = NULL, *curr = head, *next;
    for (int i = 0; i < k;i++)
    {
        if(curr!=NULL)
        {
            next = curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }
        else
        {
            break;
        }
    }

    nextHead = curr;
    return prev;
}
struct node *reverse (struct node *head, int k)
{
    node *curr=head,*prev=NULL,*next,*start,*end,*nextHead;
    queue<pair<node*,node*>> q;
    if(head==NULL||head->next==NULL)
        return head;

    end = head;
    while(end!=NULL)
    {
        start = helper(end, k, nextHead);
        q.push({start, end});
        end = nextHead;
    }

    tie(start,end) = q.front();
    node *ans=start,*temp = end,*temp1;
    q.pop();
    while(!q.empty())
    {
        tie(start,end) = q.front();
        // cout << start->val << " " << end->val << endl;
        q.pop();
        temp->next = start;
        temp=end;
        
    }
    if(temp!=NULL)
        temp->next = NULL;
    return ans;
    // Complete this method
}

int main()
{
    int n=8,k=3;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    node *head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < n;i++)
    {
        node *newNode = new node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    node *ans = reverse(head, k);
    temp = ans;
    // cout <<"ans = "<< temp->val << endl;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}