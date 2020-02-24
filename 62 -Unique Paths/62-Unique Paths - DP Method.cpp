/*
Author: Liam
Date: Feb 14, 2020
0 ms
8.2MB

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1&&n==1) return 1;            //edge case of 1x1 grid
        double grid[m][n];
        //make left column all 1
        for(int i = 1; i<m;i++){
            grid[i][0] = 1;
        }
        //make top row all 1
        for(int j = 1; j<n; j++){
            grid[0][j] = 1;
        }
        //dp
        for(int i=1; i<m; i++){
            for(int j=1 ; j<n; j++){
                grid[i][j] = grid[i-1][j]+grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};