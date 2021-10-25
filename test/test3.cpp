// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(vector<int> &p, int i, int j)
{
	if (i == j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j] = INT_MIN;
	for (int k = i; k < j; k++)
	{
		dp[i][j] = max(
			dp[i][j], matrixChainMemoised(p, i, k)
					+ matrixChainMemoised(p, k + 1, j)
					+ p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}
int MatrixChainOrder(int N,vector<int> &A)
{
	int i = 1, j = N - 1;
	return matrixChainMemoised(A, i, j);
}

// Driver Code
int main()
{
	vector<int> arr = { 3,4,5,6 };
	int n = arr.size();
	memset(dp, -1, sizeof dp);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(n,arr);
}

// This code is contributed by Sumit_Yadav
