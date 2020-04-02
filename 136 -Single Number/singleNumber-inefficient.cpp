/*
Author: Liam
Date: Apr 2, 2020
Runtime: 976 ms, faster than 5.13% of C++ online submissions for Single Number.
Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Single Number.

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4


*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i<nums.size(); i++){
            int curr = nums[i];
            vector<int>::iterator it = find(nums.begin()+i+1, nums.end(), curr);
            int index = distance(nums.begin(), it);
            if(it != nums.end()){
                nums.erase(nums.begin()+index);
            } else {
                return curr;
            }
        }
        return 0;
    }
};

