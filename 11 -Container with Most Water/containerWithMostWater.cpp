/*
Author: Liam
Date: Mar 10, 2020
12 ms
8.9MB

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

(access image below)
https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            int h = min(height[left],height[right]);
            int w = right-left;
            int area = h*w;
            if(area>max) max = area;
            if(height[left]<=height[right]) {
                left++;
                continue;
            }
            if(height[left]>height[right]) right--;
        }
        return max;
    }
};

//testcases
// []
// [1,1]
// [5,7,4,8,9,1]
// [1,8,6,2,5,4,8,3,7]