#include <bits/stdc++.h>
using namespace std;

class Node
{

    // constructor
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int getMedian(Node *root,int preCount,int &target,int &ans)
{
    if(root==NULL)
        return preCount;
    else
    {
        if(ans!=-1)
            return preCount;
        int count = getMedian(root->left, preCount, target, ans)+1;
        if(count==target)
        {
            ans = root->data;
        }
        return getMedian(root->right, count, target, ans);
    }
}
int getCount(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return (1 + getCount(root->left) + getCount(root->right));
}
double solve(Node* root)
{
    int count = getCount(root);
    cout << "Count = " << count;
    if(count%2==1)
    {
        count = (count / 2)+(count%2);
        cout << "Target = " << count << endl;
        int ans = -1, preCount = 0;
        getMedian(root, preCount, count, ans);
        return ans;
    }
    else
    {
        count = count / 2;
        int ans1 = -1, ans2 = -1,preCount=0;
        cout << "Target = " << count << endl;
        getMedian(root, preCount, count, ans1);
        count++;
        getMedian(root, preCount, count, ans2);
        return (ans1 + ans2) / 2;
    }
}

int main()
{
    Node *root1, *root2;
    root1 = new Node(5);              /*             5        */
    root1->left = new Node(3);        /*           /   \      */
    root1->right = new Node(7);       /*         3     7     */
    root1->left->left = new Node(2);  /*    / \   / \    */
    root1->left->right = new Node(4); /*  2   4 6   8 */
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    // formation of BST 2
    root2 = new Node(10);             /*           10         */
    root2->left = new Node(6);        /*           /   \ */
    root2->right = new Node(15);      /*        6     15 */
    root2->left->left = new Node(3);  /*    / \   /  \ */
    root2->left->right = new Node(8); /*  3  8  11  18    */
    root2->right->left = new Node(11);
    // root2->right->right = new Node(18);

    int x = 16;
    cout << solve(root2) << endl;
}