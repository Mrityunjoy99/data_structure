#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int threeSumMulti(vector<int> &arr, int target)
{
    unordered_map<int, vector<int>> um;
    vector<int> v;
    int num, index;
    long ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (um.find(arr[i]) == um.end())
        {
            um.insert({arr[i], {i}});
        }
        else
        {
            um[arr[i]].push_back(i);
        }
    }
    for (auto i = um.begin(); i != um.end(); i++)
    {
        cout << i->first << " : ";
        printVector(i->second);
    }
    cout << endl
         << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            num = target - arr[i] - arr[j];
            if (um.find(num) != um.end())
            {
                v = um[num];
                // cout << num << " : ";
                // printVector(v);
                index = 0;
                while ((index<v.size())&&(v[index] < j))
                {
                    index++;
                };
                cout <<"i = "<<i<<"\tj = "<<j<<"\tnum = "<< num << " : " << v.size()-index << endl;
                ans += (((v.size() - index)>0)?(v.size() - index):0);
                // ans += v.size();
                ans %= (1000000007);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 8;
    cout << threeSumMulti(arr, target) << endl;
}