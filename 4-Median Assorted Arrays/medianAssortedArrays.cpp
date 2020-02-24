//based on Tushar Roy Youtube
//https://www.youtube.com/watch?v=LPFhl65R7ww&t=1013s

/*
Author: Liam
Date: Feb 24, 2020
21 ms
9.6MB

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

//based on Tushar Roy Youtube
//https://www.youtube.com/watch?v=LPFhl65R7ww&t=1013s

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        //assure first array is the shortest
        if(a>b) return findMedianSortedArrays(nums2,nums1);
        //for empty arrays
        if(a==0) {
            if(b%2==0){
                int midR = b/2;
                int midL = midR-1;
                return (double)(nums2[midR]+nums2[midL])/2;
            } else{
                int mid = b/2;
                return nums2[mid];
            }
        }
        
        const int low = INT_MIN;
        const int high = INT_MAX;
        int start = 0;
        int end = a;
        
        while(start <= end){   
            int topR = max((start+end)/2, 0);
            int bottomR = (a + b + 1)/2 - topR;
            
            int topRV = topR==a ? high : nums1[topR];
            int topLV = topR==0 ? low : nums1[topR-1];
            int bottomRV = bottomR==b ? high : nums2[bottomR];
            int bottomLV = bottomR==0 ? low : nums2[bottomR-1];
            
            if(topLV <= bottomRV && bottomLV <= topRV){
                if ((a+b)%2 == 0){
                    double left = max(topLV,bottomLV);
                    double right = min(topRV,bottomRV);
                    return (left + right)/2;
                } else {
                    double x = topLV;
                    double y = bottomLV;
                    return max(x, y);
                }
            } else if(topLV > bottomRV){
                end = topR-1;
            } else {
                start = topR + 1;
            }
            
        }
        //should not reach here
        return 1;
    }
};

//testcases
// [3]
// [1,2,4,5,6]
// [3]
// [-2,-1]
// []
// [2,3]
// [1]
// []
// []
// [1]
// [0,0]
// [0,0]
// [2,2]
// [2,2]
// [1,3]
// [2]
// [2]
// [1,3]
// [1,2]
// [3,4]
// [1,3,4,6,7]
// [2,3,4,5,55,67]