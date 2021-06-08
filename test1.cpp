#include<bits/stdc++.h>
using namespace std;

void DFSUtil(vector<vector<char>>& grid,int i,int j)
{
    // unordered_set<pair<int,int>> vis;
    int A = grid.size();
    int B = grid[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});
    grid[i][j]='0';
    pair<int,int> p;
    int x,y;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        x = p.first;
        y = p.second;
        if((x-1>=0&&y-1>=0)&&grid[x-1][y-1]=='1')
        {
            q.push({x-1,y-1});
            grid[x-1][y-1] ='0';
        }
        if((x-1>=0)&&grid[x-1][y]=='1')
        {
            q.push({x-1,y});
            grid[x-1][y]=='0';
        }
        if((x-1>=0&&y+1<B)&&grid[x-1][y+1]=='1')
        {
            q.push({x-1,y+1});
            grid[x-1][y+1]=='0';
        }
        if((y+1<B)&&grid[x][y+1]=='1')
        {
            q.push({x,y+1});
            grid[x][y+1]=='0';
        }
        if((x+1<A&&y+1<B)&&grid[x+1][y+1]=='1')
        {
            q.push({x+1,y+1});
            grid[x+1][y+1]=='0';
        }
        if((x+1<A)&&grid[x+1][y]=='1')
        {
            q.push({x+1,y});
            grid[x+1][y]=='0';
        }
        if((x+1<A&&y-1>=0)&&grid[x+1][y-1]=='1')
        {
            q.push({x+1,y-1});
            grid[x+1][y-1]=='0';
        }
        if((y-1>=0)&&grid[x][y-1]=='1')
        {
            q.push({x,y-1});
            grid[x][y-1]=='0';
        }
    }
}
int numIslands(vector<vector<char>>& grid) 
{
    int count=0;
    
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]=='1')
            {
                count++;
                DFSUtil(grid,i,j);
            }
        }
    }
    return count;
    // Code here
}
int main()
{
    vector<vector<char>> grid = {
        {'0','1'},
        {'1','0'},
        {'1','0'},
        {'1','0'}
    };
    cout<<numIslands(grid)<<endl;
}