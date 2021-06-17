#include<bits/stdc++.h>
using namespace std;

void preWork(vector<string> &wordList,vector<vector<string>> &tempList,unordered_map<string,int> &um)
{
    int index = 0;
    string s;
    for(auto word:wordList)
    {

        for(int j=0;j<word.length();j++)
        {
            s = word;
            s[j] = '*';
            cout << s << endl;
            if(um.find(s)==um.end())
            {
                um.insert({s,index++});
            }
            tempList[um[s]].push_back(word);
        }
    }
}
void printWordList(vector<string> &wordList,vector<vector<string>> &tempList,unordered_map<string,int> &um)
{
    string s;
    cout << "Printing Word List ....." << endl;
    for(auto word:wordList)
    {
        for(int j=0;j<word.length();j++)
        {
            s = word;
            s[j] = '*';
            cout << s << "\t:\t";
            for(auto i:tempList[um[s]])
                cout << i << " ";
            cout << endl;
        }
    }
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
    // cout << tempList.size();
    unordered_map<string,int> um,wordMap;
    bool isBeginPresent = false;
    for(auto i:wordList)
    {
        if(i==beginWord)
            isBeginPresent = true;
    }
    if(!isBeginPresent)
        wordList.push_back(beginWord);
    vector<vector<string>> tempList(((wordList.size())*(wordList[0].length())));
    preWork(wordList,tempList,um);

    // printWordList(wordList, tempList, um);

    vector<bool> vis(wordList.size(),false);
    for(int i=0;i<wordList.size();i++)
    {
        wordMap.insert({wordList[i],i});
    }
    int depth;
    string str,temp_str;
    queue<pair<string,int>> q;
    q.push({beginWord,0});
    vis[wordMap[beginWord]] = true;
    while(!q.empty())
    {
        tie(str,depth) = q.front();
        q.pop();
        if(str==endWord)
            return depth+1;
        for(int j=0;j<str.size();j++)
        {
            temp_str = str;
            temp_str[j] = '*';
            for(auto word:tempList[um[temp_str]])
            {
                if(!vis[wordMap[word]])
                {
                    q.push({word,depth+1});
                    vis[wordMap[word]] = true;
                }
            }
        }
    }
    return 0;
}

int main()
{
    vector<string> wordList = {"hog"};
    // cout << wordList.size() << endl;
    string startWord = "hot", endWord = "hog";
    cout<<"ans = "<<ladderLength(startWord, endWord, wordList);
}