#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &arr, vector<string> &v, vector<vector<bool>> vis, string s, int i, int j)
{
    if ((i < 0) || (i >= arr.size()) || (j < 0) || (j >= arr.size()))
        return;
    vis[i][j] = true;
    
    if (arr[i][j] == 0)
        return;
    else if ((i == arr.size() - 1) && (j == arr.size() - 1))
    {
        cout << s << endl;
        v.push_back(s);
        return;
    }
    cout << "i : "<<i<<"\tj : "<<j << endl;
    int dirX[] = {0, 1, 0, -1};
    int dirY[] = {1, 0, -1, 0};
    char dirC[] = {'D', 'R', 'U', 'L'};
    int i1, j1;
    for (int x = 0; x < 4; x++)
    {
        // string s1 = ;
        i1 = i + dirX[x];
        j1 = j + dirY[x];
        if (!vis[i1][j1])
            helper(arr, v, vis, s + dirC[x], i1, j1);
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> v;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string s = "";
    
    helper(m, v, vis, s, 0, 0);
    return v;
    // Your code goes here
}

int main()
{
    int N = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    vector<string> vstr = findPath(m, N);
}