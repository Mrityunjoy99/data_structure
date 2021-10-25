#include <bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n)
{
    int i = 1, j = n - 2, ll = arr[0], rl = arr[n - 1];
    int sum = 0;
    while (i <= j)
    {
        cout << i << " " << j << endl;
        if (ll < rl)
        {
            cout << "ll < rl : ll = " << ll << "\trl = " << rl << endl;
            if (arr[i] >= ll)
            {
                ll = arr[i];
            }
            else
            {
                cout << " arr[i] = " << arr[i] << endl;
                sum += (ll - arr[i]);
            }
            i++;
        }
        else
        {
            if (arr[j] >= rl)
            {
                rl = arr[j];
            }
            else
            {
                sum += (rl - arr[j]);
            }
            j--;
        }
    }
    return sum;
    // Code here
}

int main()
{
    int arr[] = {7, 4, 0, 9};
    int n = 4;
    cout << trappingWater(arr, n) << endl;
}