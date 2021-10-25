#include<bits/stdc++.h>
using namespace std;

int segment(int x, vector<int> space)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> st;
    int mx = INT_MIN;
    for (int i = 0; i < x; i++)
    {
        pq.push(space[i]);
        st.insert(space[i]);
    }
    mx = pq.top();
    for (int i = x; i < (int)space.size(); i++)
    {
        st.erase(space[i - x]);
        pq.push(space[i]);
        st.insert(space[i]);

        while(st.find(pq.top())==st.end())
            pq.pop();
        mx = max(mx, pq.top());
    }
    return mx;
}

int main()
{
    int x = 2;
    vector<int> space = {8, 2, 4, 6};
    cout << segment(x, space) << endl;
}