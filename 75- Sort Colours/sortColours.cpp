/*
Author: Liam
Date: Feb 29, 2020
4 ms
8.1MB

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:

    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
    Could you come up with a one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==0) return;
        int num1 = 0;
        int num2 = 0;
        if(nums[0]==1) num1=1;
        if(nums[0]==2) num2=1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == 2){
                num2++;
                continue;
            }
            if(nums[i] == 1){
                num1++;
                nums.insert(nums.begin()+i-num2,1);
                nums.erase(nums.begin()+i+1);
            }
            if(nums[i] == 0){
                nums.insert(nums.begin()+i-(num1+num2),0);
                nums.erase(nums.begin()+i+1);
            }
        }
    }
};

//testcases
// []
// [0,1,2,1,0,2,1,1,0]
// [1,2]
// [2,1]
// [2,0,2,1,1,0]