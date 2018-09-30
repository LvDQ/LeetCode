You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

Difficulty: Medium

  class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[0].size();j++){
                if(rooms[i][j]==0)
                    helper(rooms,i,j,0);
            }
        }
    }

    void helper(vector<vector<int>>& rooms,int i,int j,int step){
        if(i>=rooms.size()||i<0||j>=rooms[0].size()||j<0)return;
        if(rooms[i][j]==-1)return;
        // cout<<step<<" "<<rooms[i][j]<<endl;
        if(step>rooms[i][j])return;
        rooms[i][j]=step;
        helper(rooms,i+1,j,step+1);
        helper(rooms,i-1,j,step+1);
        helper(rooms,i,j+1,step+1);
        helper(rooms,i,j-1,step+1);
    }
};