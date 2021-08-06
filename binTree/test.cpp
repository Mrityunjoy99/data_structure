#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
        Node(){}
        Node(int num)
        {
            data = num;
            left =  NULL;
            right = NULL;
        }
};

void insertNode(Node* root,int val)
{
    Node *newNode = new Node(val);
    Node *temp = root;
    while(1)
    {
        // cout << "InsertNode called with value " << val << endl;
        if(val<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left = newNode;
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if(val>temp->data)
            {
                if(temp->right==NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                    temp = temp->right;
            }
        }
    }
}

int greaterSum(Node *root,int preSum)
{
    if(root==NULL)
        return 0;
    int val = root->data;
    int rightVal = greaterSum(root->right, preSum);
    if(root->right!=NULL)
        root->data = rightVal;
    else
        root->data = rightVal+preSum;
    if(root->left==NULL)
        return root->data + val;
    else
    {
        // cout << "preSum = " << preSum << "\tRight Val = " << rightVal << "\tValue = " << val << endl;
        int leftVal = greaterSum(root->left, root->data + val);
        return leftVal;
    }
}

void printInorder(Node *root)
{
    if(root==NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
struct Node *newNode(int item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
int main(int argc, const char** argv) {
    // Node *root = new Node(10);
    // insertNode(root,5);
    // insertNode(root,7);
    // insertNode(root,3);
    // insertNode(root,15);
    // insertNode(root,11);
    // insertNode(root,18);
    // insertNode(root,16);

    struct Node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);

    printInorder(root);
    cout << endl;
    greaterSum(root, 0);
    printInorder(root);
    cout << endl;
}