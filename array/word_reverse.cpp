#include <bits/stdc++.h>
using namespace std;

void reverse_words(char *sentence)
{
    string str = "";
    stack<string> st;
    int i = 0, l = str.length(), start = 0, end;
    while (sentence[i] != '\0')
    {
        str += sentence[i];
        i++;
    }
    // cout << str;
    i = 0;
    l = str.length();
    while (i < l)
    {
        // cout << i;
        if (str[i] == ' ')
        {
            if (i > start)
            {
                end = i;
                // cout << str.substr(start, end-start) << endl;
                st.push(str.substr(start, end-start));
                start = end + 1;
            }
            else
                cout << "Error" << endl;
        }
        i++;
    }
    // cout << str.substr(start, i-start) << endl;
    st.push(str.substr(start, i-start));
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        ans += ' ';
    }
    i = 0;
    while (i < ans.length())
    {
        sentence[i] = ans[i];
        i++;
    }

    //TODO: Write - Your - Code
}

int main()
{
    char sentence[] = "C++ Love We";
    reverse_words(sentence);
    cout << "ans : ";
    for (int i = 0; sentence[i] != '\0';i++)
        cout << sentence[i];
    cout << endl;
}