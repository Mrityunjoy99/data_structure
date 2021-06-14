#include<bits/stdc++.h>
using namespace std;
struct cell
{
    int x,y,depth;
    cell(int xVal,int yVal,int dVal)
    {
        x = xVal;
        y = yVal;
        depth = dVal;
    }
    void setParam(int xVal,int yVal,int dVal)
    {
        x = xVal;
        y = yVal;
        depth = dVal;
    }
};
int getSteps(vector<vector<bool>> &vis,pair<int,int> &dest,int N,int x,int y,vector<int> &dx,vector<int> &dy)
{
    queue<cell> q;
    cell c(x,y,0);
    q.push(c);
    vis[x][y] = true;
    int temp_x,temp_y,temp_depth,X,Y;
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        temp_x = c.x;
        temp_y = c.y;
        temp_depth = c.depth;
        if(temp_x==dest.first&&temp_y==dest.second)
        {
            return temp_depth;
        }

        for(int i=0;i<8;i++)
        {
            X = temp_x + dx[i];
            Y = temp_y + dy[i];
            if(X>=0&&X<N&&Y>=0&&Y<N&&(!vis[X][Y]))
            {
                c.setParam(X,Y,temp_depth+1);
                q.push(c);
                vis[X][Y]  = true;
            }
        }
    }
    
}
int minStepsCounter(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    vector<vector<bool>> arr(N,vector<bool>(N,false));
    pair<int,int> dest(TargetPos[0]-1,TargetPos[1]-1);
    vector<int> dx = {-2,-2,-1,-1,1,1,2,2,};
    vector<int> dy = {-1,1,-2,2,-2,2,-1,1};
    // cout<<"starting operations "<<endl;
    return getSteps(arr,dest,N,KnightPos[0]-1,KnightPos[1]-1,dx,dy);
}

int main()
{
    int N=6;
    vector<int> knightPos = {4, 5},targetPos = {1, 1};
    cout<<minStepsCounter(knightPos,targetPos,N)<<endl;
}