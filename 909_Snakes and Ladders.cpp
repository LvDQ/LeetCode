On an N x N board, the numbers from 1 to N*N are written boustrophedonically starting from the bottom left of the board, and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:


You start on square 1 of the board (which is always in the last row and first column).  Each move, starting from square x, consists of the following:

You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6, provided this number is <= N*N.
(This choice simulates the result of a standard 6-sided die roll: ie., there are always at most 6 destinations.)
If S has a snake or ladder, you move to the destination of that snake or ladder.  Otherwise, you move to S.
A board square on row r and column c has a "snake or ladder" if board[r][c] != -1.  The destination of that snake or ladder is board[r][c].

Note that you only take a snake or ladder at most once per move: if the destination to a snake or ladder is the start of another snake or ladder, you do not continue moving.  (For example, if the board is `[[4,-1],[-1,3]]`, and on the first move your destination square is `2`, then you finish your first move at `3`, because you do not continue moving to `4`.)

Return the least number of moves required to reach square N*N.  If it is not possible, return -1.

Example 1:

Input: [
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,35,-1,-1,13,-1],
[-1,-1,-1,-1,-1,-1],
[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
At the beginning, you start at square 1 [at row 5, column 0].
You decide to move to square 2, and must take the ladder to square 15.
You then decide to move to square 17 (row 3, column 5), and must take the snake to square 13.
You then decide to move to square 14, and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
It can be shown that you need at least 4 moves to reach the N*N-th square, so the answer is 4.
Note:

2 <= board.length = board[0].length <= 20
board[i][j] is between 1 and N*N or is equal to -1.
The board square with number 1 has no snake or ladder.
The board square with number N*N has no snake or ladder.


difficulty: Medium


Method: when it comes to least step problem, 80% we can use BFS 


typedef pair<int,int> ii;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        // int res=-1;
        int step=0;
        int n=board.size();
        
        
        set<ii> visited;
        queue<ii> Q;
        Q.push({n-1,0});
        while(!Q.empty()){
            step++;
            int size=Q.size();
            while(size--){
                auto cur=Q.front();
                Q.pop();
                int row=cur.first,col=cur.second;
                int num=(n-1-row)*n+((n-1-row)%2?(n-col):(col+1));
                // cout<<"origin: "<<row<<" "<<col<<" "<<num<<endl;
                for(int i=1;i<=6;i++){
                    int nnum=num+i;
                    // cout<<nnum<<endl;
                    if(nnum>=n*n)return step;
                    nnum--;
                    int nrow=n-1-nnum/n;
                    nnum%=n;
                    int ncol=(n-1-nrow)%2?(n-1-nnum):nnum;
                    // cout<<nrow<<" "<<ncol<<endl;
                    if(visited.count({nrow,ncol})<=0){
                        visited.insert({nrow,ncol});
                        if(board[nrow][ncol]!=-1){
                            int tmp=board[nrow][ncol];
                            if(tmp>=n*n)return step;
                            tmp--;
                            nrow=n-1-tmp/n;
                            tmp%=n;
                            ncol=(n-1-nrow)%2?(n-1-tmp):tmp;
                            if(visited.count({nrow,ncol})<=0)
                            Q.push({nrow,ncol});
                        }
                        else{
                            Q.push({nrow,ncol});
                        }
                    }
                    
                }
            }
        }
        return -1;
    }
};