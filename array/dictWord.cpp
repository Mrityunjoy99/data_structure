#include<bits/stdc++.h>
using namespace std;

void printDP(vector<vector<int>> &dp)
{
    for(auto r:dp)
    {
        for(auto i:r)
            cout << i << "\t";
        cout << endl;
    }
}

int checkExhists(vector<string> &dict,string str)
{
    unordered_set<string> fastDict;
    for(string words:dict)
        fastDict.insert(words);

    int l = str.length();
    cout << l << endl;
    vector<vector<int>> dp(l + 1, vector<int>(l + 1, 0));
    // int len = 1;
    for (int len = 0; len < l; len++)
    {
        for (int i = 0; i + len < l;i++)
        {
            if(fastDict.find(str.substr(i,len+1))!=fastDict.end())
                dp[i][i + len] = 1;
            else
            {
                for (int k = 0; k < len;k++)
                {
                    if((dp[i][i+k]==1)&&(dp[i+k+1][i+len]==1))
                    {
                        dp[i][i + len] = 1;
                        break;
                    }
                }
                if(dp[i][i + len] != 1)
                    dp[i][i + len] = -1;
            }
        }
    }
    printDP(dp);
    return dp[0][l - 1];
}


int main()
{
    vector<string> dict = {"i", "a","am", "x","axe"};
    string str = "iamax";
    cout << checkExhists(dict, str) << endl;
}