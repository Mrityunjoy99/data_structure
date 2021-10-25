#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> v = {1,1,2,2,3,4}
    unordered_map<int, int> mp;
    mp[1]++;
    mp[2]++;
    mp[1]++;
    mp[2]--;
    mp.erase(2);
    cout << mp.size() << endl;
}