/*
Author: Liam
Date: Feb 5, 2020
36 ms
11.8MB

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:

Coud you solve it without converting the integer to a string?

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        
        int temp = 0;
        
        std::vector<int> arr;
        int y = x;
        while (y != 0){
            int digit = y%10;
            arr.push_back(digit);
            y /= 10;
        }
        int size = arr.size();
        for(int i=0; i<size ; i++){
            temp += arr[i]*(pow(10,size-1-i));
        }
        return (temp==x)?true:false;
    }
};