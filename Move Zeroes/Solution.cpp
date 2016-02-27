class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size(),count=0,i=0;
        if(length==0)return;
        for(i=0;i<length;i++)
        {
            if(nums[i]==0)count++;
            else nums[i-count] = nums[i];
        }
        i = length;
        while(count)
        {
            nums[i-count] = 0;
            count--;
        }
    }
 
};