#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &arr, vector<int> &v, int r, int c, int k)
{
    cout << "k = " << k << endl;

    for (int i = k; i < c - k - 1; i++)
    {
        cout << arr[k][i] << " + ";
        v.push_back(arr[k][i]);
    }
    for (int i = k; i < r - k - 1; i++)
    {
        cout << arr[i][c - k - 1] << " - ";
        v.push_back(arr[i][c - k - 1]);
    }
    int lim = k + 1;
    for (int i = c - k - 1; i >= (k + 1); i--)
    {
        cout << arr[r - k - 1][i] << " * ";
        v.push_back(arr[r - k - 1][i]);
    }
    for (int i = r - k - 1; i >= (k + 1); i--)
    {
        cout << arr[i][k] << " / ";
        v.push_back(arr[i][k]);
    }
    cout << endl;
}
vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    vector<int> v;
    for (int i = 0; i < (r / 2+r%2 ); i++)
    {
        helper(matrix, v, r, c, i);
    }

    // code here
}

int main()
{
    // vector<vector<int>> matrix = {{1, 2, 3, 4},
    //                               {5, 6, 7, 8},
    //                               {9, 10, 11, 12},
    //                               {13, 14, 15, 16}};
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    vector<int> v = spirallyTraverse(matrix, matrix.size(), matrix[0].size());
    // for(int i:v)
    //     cout << i << " ";
    // cout << endl;
}