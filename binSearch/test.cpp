#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {5, 6, 7, 7, 6, 5, 5, 6};
    // cout << " v.begin() = " << v.begin() << endl;
    sort(v.begin(), v.end());
    for(int i:v)
        cout << i << " ";
    cout << endl;
    auto lower = lower_bound(v.begin(), v.end(), 6);
    cout << (lower-v.begin()) << endl;

    auto var = binary_search(v.begin(), v.end(), 3);
    cout << var << endl;
}