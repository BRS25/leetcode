/*
Author: Liam
Date: Feb 13, 2020
0 ms
8.1MB

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
    double factorial(int a){
	    double fact=1;
	    while(a>=1){
		fact=fact*a;
		a--;
	    }
	    return fact;
    }
    int nCr(int n, int r) { 
        return factorial(n) / (factorial(r) * factorial(n - r)) + 0.5;      //0.5 needed for double to int fix
    } 
    int uniquePaths(int m, int n) {
        return nCr(m+n-2,m-1);
        
    }
};