/*
Author: Liam
Date: Feb 5, 2020
28 ms
8.7MB

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.

Note:

    The given board contain only digits 1-9 and the character '.'.
    You may assume that the given Sudoku puzzle will have a single unique solution.
    The given board size is always 9x9.


*/
class Solution {
public:
    /*
    returns true if number x has not been used in given row, otherwise false
    */
    bool rowCheck(vector<vector<char>>& board, int row, int x){
        for(int i=0; i<9; i++){
            if((int)board[row][i]-48==x) return false;
        }
        return true;
    }
    
    /*
    returns true if number x has not been used in given column, otherwise false
    */
    bool colCheck(vector<vector<char>>& board, int col, int x){
        for(int i=0; i<9; i++){
            if((int)board[i][col]-48==x) return false;
        }
        return true;
    }
    
    /*
    returns true if number x has not been used in given block, otherwise false
    */
    bool blockCheck(vector<vector<char>>& board, int row, int col, int x){
        int blockr = 0;
        int blockc = 0;
        if(row==0||row==1||row==2) blockr=0;
        if(row==3||row==4||row==5) blockr=3;
        if(row==6||row==7||row==8) blockr=6;
        
        if(col==0||col==1||col==2) blockc=0;
        if(col==3||col==4||col==5) blockc=3;
        if(col==6||col==7||col==8) blockc=6;
        //int rMIN = blockr;
        int cMIN = blockc;
        int rMAX = blockr+3;
        int cMAX = blockc+3;
        for(blockr; blockr<rMAX; blockr++){
            blockc = cMIN;
            for(blockc; blockc<cMAX; blockc++){
                if((int)board[blockr][blockc]-48==x) return false;
            }
        }
        return true;
    }
    
    bool containBlank(vector<vector<char>>& board) {
        for (int i = 0; i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j] == '.') return true;
            }
        }
        return false;
    }
    
    bool recSolveSudoku(vector<vector<char>>& board) {
        if (containBlank(board)==false) return true;
        for (int i = 0; i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j]=='.'){
                    for (int x = 1; x<10; x++){
                    if (rowCheck(board,i,x) && colCheck(board,j,x) && blockCheck(board,i,j,x)){
                        cout<<x<<endl;
                        board[i][j] = x+48;
                        if (recSolveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
                }
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        if(recSolveSudoku(board)) return;
    }
};