#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int(*p)[5];
    // int arr[2][5] = {{2, 3, 4, 5, 6}, {7, 8, 9, 10, 11}};
    // p = arr;
    // cout << (*(p+1))[1] << endl;

    int a = 10,b=5;
    // int const *p;
    const int *p;
    p = &a;
    // p = &b;
    a = 6;
    cout << *p << endl;
}