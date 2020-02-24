class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        bool isDec = true;
        bool reachedEnd = false;
        for (int i=0; i<size; i++){
            if (nums[size-1]==nums[i]) reachedEnd=true;
            //cout<<"i="<<i<<endl;
            //case where need to sort in ascending
            if(nums[size-1]!=nums[i] && nums[i]<nums[i+1]) isDec=false;
            if(reachedEnd && isDec==true){
                for (int j = 0; j<size/2;j++){
                    int temp = nums[i];
                    nums[i] = nums[size-1-i];
                    nums[size-1-i] = temp;
                }
                return;
            }
            
            if(reachedEnd && nums[i-1]<nums[i]){
                int temp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = temp;
                return;
            }
            if(reachedEnd && nums[i-1]>nums[i]){
                int temp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = temp;
                return;
            }
        }
    }
};

[2,3,1]
[3,1,2]
[3,2,1]
[1,2,3]
[1,1,5]