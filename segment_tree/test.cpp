#include<bits/stdc++.h>
using namespace std;

int getParent(int n)
{
    return ((n - 1) / 2);
}
int getRightChild(int n)
{
    return (2 * n + 2);
}

int getLeftChild(int n)
{
    return (2 * n + 1);
}

int helper(vector<pair<int,int>> &price_rating,vector<vector<int>> &seg,int i,int l,int r)
{
    if(l>r)
        return 0;
    seg[i][1] = price_rating[l].first;
    seg[i][2] = price_rating[r].first;
    if(l==r)
    {
        seg[i][0] = price_rating[l].second;
    }
    else
    {
        int mid = (l + r) / 2;
        seg[i][0] = max(helper(price_rating, seg, getLeftChild(i), l, mid), helper(price_rating, seg, getRightChild(i), mid + 1, r));
    }
    return seg[i][0];
}

// void createSegTree(vector<pair<int,int>> &price_rating,vector<vector<int>> &seg)
// {
//     helper(price_rating, seg, 0, 0, price_rating.size() - 1);
// }

void printSegTree( vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i][0] << '\t';
    cout << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i][1] << '\t';
    cout << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i][2] << '\t';
    cout << endl;
}

int searchInSegTree(vector<vector<int>> &seg, int i, pair<int,int> &range)
{
    if(((range.first)<=seg[i][1])&&(range.second>=(seg[i][2])))
        return seg[i][0];
    else if((seg[i][2]<range.first)||(seg[i][1]>range.second))
    {
        return -1;
    }
    else
    {
        return max(searchInSegTree(seg, getLeftChild(i), range), searchInSegTree(seg, getRightChild(i), range));
    }
    
}

void solve(vector<pair<int,int>> &price_rating,vector<pair<int,int>> &query)
{
    int size = pow(2, ceil(log2(price_rating.size())) + 1);
    vector<vector<int>> seg(size, vector<int>(3,-1));
    sort(price_rating.begin(), price_rating.end());
    helper(price_rating, seg, 0, 0, price_rating.size() - 1);
    for(auto q:query)
    {
        cout << searchInSegTree(seg, 0, q) << endl;
    }
    // printSegTree(seg);
}

int main()
{
    vector<pair<int, int>> price_rating = {
        {1000, 300},
        {1100, 400},
        {1300, 200},
        {1700, 500},
        {2000, 600}};
    vector<pair<int, int>> query = {
        {1000, 1400},
        {1200,1250},
        {1700, 1900},
        {0, 2000}};
    solve(price_rating, query);
}