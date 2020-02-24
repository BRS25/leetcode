/*
Author: Liam
Date: Aug, 2019
132 ms
9.1MB

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> answer = {0, 0};
        
        for(int i=0; i<std::size(nums); i++){
            for(int j=i+1; j<std::size(nums); j++){
                //int tempSum = 0;
                int tempSum = nums[i] + nums[j];
                if(tempSum == target){
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
            }
            
        }
        return answer;
    }
};