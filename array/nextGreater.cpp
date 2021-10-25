#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for(int i:v)
        cout << i << " ";
    cout << endl;
}

vector<int> helper(vector<int> &nums)
{
    stack<int> s;
    vector<int> ans(nums.size());
    int index;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }
        else
        {
            while ((!s.empty()) && (nums[s.top()] < nums[i]))
            {
                ans[s.top()] = nums[i];
                s.pop();
            }
            // if(nums[index]>=nums[i])
            //     s.push(index);
            s.push(i);
        }
    }
    while (!s.empty())
    {
        index = s.top();
        s.pop();
        ans[index] = -1;
    }
    // printVector(ans);
    return ans;
}
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> um, um1;
    for (int i = 0; i < nums1.size(); i++)
        um.insert(make_pair(nums1[i], i));

    for (int i = 0; i < nums2.size(); i++)
    {
        if (um.find(nums2[i]) != um.end())
        {
            um1.insert(make_pair(um[nums2[i]], i));
        }
    }
    vector<int> nextGreater = helper(nums2), ans(nums1.size());

    int j;
    for (int i = 0; i < nums1.size(); i++)
    {
        j = um1[i];
        ans[i] = nextGreater[j];
    }
    return ans;
}

int main()
{
    vector<int> v1 = {4, 1, 2}, v2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(v1, v2);
    printVector(ans);
}