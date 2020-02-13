/*
Author: Liam
Date: Feb 7, 2020
36 ms
16.7MB

Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 
'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent 
(above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines 
are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'),
 return the board after revealing this position according to the following rules:


    1) If a mine ('M') is revealed, then the game is over - change it to 'X'.
    2) If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') 
      and all of its adjacent unrevealed squares should be revealed recursively.
    3) If an empty square ('E') with at least one adjacent mine is revealed, then change it to 
      a digit ('1' to '8') representing the number of adjacent mines.
    4) Return the board when no more squares will be revealed.

Note:

    1) The range of the input matrix's height and width is [1,50].
    2) The click position will only be an unrevealed square ('M' or 'E'), which also means the input 
      board contains at least one clickable square.
    3) The input board won't be a stage when game is over (some mines have been revealed).
    4) For simplicity, not mentioned rules should be ignored in this problem. For example, 
      you don't need to reveal all the unrevealed mines when the game is over, consider any cases 
      that you will win the game or flag any squares.

*/

class Solution {
public:
    
    bool identifiedM (vector<vector<char>>& board, int rowNum, int colNum, int row, int col){
        int topr = row-1;
        int botr = row+1;
        int leftc = col-1;
        int rightc = col+1;
        
        if(topr < 0) topr =0;
        if(leftc< 0) leftc=0;
        if(botr > rowNum-1) botr=rowNum-1;
        if(rightc > colNum-1) rightc=colNum-1;
        
        if(board[topr][leftc]  == 'M'||
           board[topr][col]    == 'M'||
           board[topr][rightc] == 'M'||
           board[row][leftc]   == 'M'||
           board[row][rightc]  == 'M'||
           board[botr][leftc]  == 'M'||
           board[botr][col]    == 'M'||
           board[botr][rightc] == 'M') {
            return true;
        }
        return false;
    }
    
    void solve (vector<vector<char>>& board, int rowNum, int colNum, int row, int col){
        //checking boxes around clicked box, and turn into 'B'
        int topr = row-1;
        int botr = row+1;
        int leftc = col-1;
        int rightc = col+1;
        
        if(topr < 0) topr =0;
        if(leftc< 0) leftc=0;
        if(botr > rowNum-1) botr=rowNum-1;
        if(rightc > colNum-1) rightc=colNum-1;
        
        //case where click reveals a number
        if(identifiedM(board, rowNum, colNum, row, col)) {
            toNum(board, rowNum, colNum, row, col);
            return;
        } else {
            board[row][col]='B';
        }
        
        //recursively solve adjacent sqares revealed by click
        for (int i = max(topr,0); i<min(botr+1,rowNum); i++){
            for (int j=max(leftc,0); j<min(rightc+1,colNum); j++){
                if(board[i][j]=='E'){
                    solve(board, rowNum, colNum, i, j);
                }
            }
        }
    }
    
    void toNum (vector<vector<char>>& board, int rowNum, int colNum, int row, int col){
        //checking board and assigning mine numbers
        int topr = row-1;
        int botr = row+1;
        int leftc = col-1;
        int rightc = col+1;

        if(topr < 0) topr =0;
        if(leftc< 0) leftc=0;
        if(botr > rowNum-1) botr=rowNum-1;
        if(rightc > colNum-1) rightc=colNum-1;
        
        char count = '0';

        //edge case of board with only one column
        if(colNum==1){
            if(board[topr][col]    == 'M') count++;
            if(board[botr][col]    == 'M') count++;
            if(count != '0') board[row][col] = count;
            count = '0';
            return;
        }
        
        if(board[topr][leftc]  == 'M') count++;
        if(board[topr][col]    == 'M' && col!=leftc && col!=rightc) count++;
        if(board[topr][rightc] == 'M') count++;
        if(board[row][leftc]   == 'M' && row!=topr && row!=botr) count++;
        if(board[row][rightc]  == 'M' && row!=topr && row!=botr) count++;
        if(board[botr][leftc]  == 'M') count++;
        if(board[botr][col]    == 'M' && col!=leftc && col!=rightc) count++;
        if(board[botr][rightc] == 'M') count++;
        if(count != '0') board[row][col] = count;
        count = '0';
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rowNum = board.size();
        int colNum = board[0].size();
        int row = click[0];
        int col = click[1];
        
        //clicked on a bomb 
        if(board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }
        
        solve(board, rowNum, colNum, row, col);
        return board;
    }
};