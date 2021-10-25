#include <bits/stdc++.h>
using namespace std;

int getRow(vector<vector<int>> &mat, int i, int j, int X)
{
    int mid = (i + j) / 2;
    if (i == j)
        return i;
    else if ((j - i) == 1)
    {
        if (mat[j][0] <= X)
            return j;
        else
            return i;
    }
    else
    {
        if (mat[mid][0] == X)
            return mid;
        else if (mat[mid][0] > X)
            return getRow(mat, i, mid - 1, X);
        else
            return getRow(mat, mid, j, X);
    }
}
bool getVal(vector<vector<int>> &mat, int r, int i, int j, int X)
{
    if ((i > j) || (i == j && mat[r][i] != X))
        return false;
    int mid = (i + j) / 2;
    if (mat[r][mid] == X)
        return true;
    else if (mat[r][mid] > X)
        return getVal(mat, r, i, mid - 1, X);
    else
        return getVal(mat, r, mid + 1, j, X);
}
int matSearch(vector<vector<int>> &mat, int N, int M, int X)
{
    if (X < mat[0][0] || X > mat[N - 1][M - 1])
        return 0;
    int r = getRow(mat, 0, N - 1, X);
    cout << "r = " << r << endl;
    if (getVal(mat, r, 0, M - 1, X))
        return 1;
    else
        return 0;
    // your code here
}

int main()
{
    int r, c, x;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r;i++)
    {
        for (int j = 0; j < c;j++)
        {
            cin >> mat[i][j];
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    cin >> x;
    cout << matSearch(mat, r, c, x) << endl;
}