/*
Author: Liam
Date: Feb 5, 2020
4 ms
8.6MB

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within 
the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, 
assume that your function returns 0 when the reversed integer overflows.

*/
class Solution {
public:
    int reverse(int x) {
        const int upper = pow(2,31)-1;
        const int lower = -pow(2,31);
        std::vector<int> arr;
        bool negative = false;
        if(x==0) return 0;
        if (x < 0 && x > lower) {
            negative = true;
            x *= -1;
        }
        
        while (x != 0){
            int digit = x%10;
            arr.push_back(digit);
            x /= 10;
        }
        int size = arr.size();
        long answer = 0;
        for(int i=0; i<size ; i++){
            long temp = arr[i]*(pow(10,size-1-i));
            if (temp>=upper || temp <=lower) {
                return 0;
            }
            answer += temp;
        }
        
        if (negative == true) answer *= -1;
        if (answer>=upper || answer <=lower) return 0;
        
        return answer;
    }
};