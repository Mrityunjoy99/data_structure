#include <bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
	stack<long long> st;
	vector<long long> left(n), right(n);
	for (int i = 0; i < n; i++)
	{
		cout << i << " : ";
		while ((!st.empty()) && (arr[st.top()] > arr[i]))
			st.pop();
		cout <<"after while, ";
		left[i] = (st.empty()) ? 0 : (st.top() + 1);
		cout << "after left,";
		st.push(i);
		cout << "after push ";
	}
	while (!st.empty())
		st.pop();
	for (int i = n - 1; i >= 0; i--)
	{
		while ((!st.empty()) && (arr[st.top()] > arr[i]))
			st.pop();
		right[i] = st.empty() ? n - 1 : (st.top() - 1);
		st.push(i);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = (long long)max(ans, ((right[i] - left[i] + 1) * arr[i]));
	}
	return ans;
	// Your code here
}

int main()
{
	long long hist[] = {6, 2, 5, 4, 5, 1, 6};
	int n = 7;
	cout << getMaxArea(hist, n) << endl;
}
