class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,res,len=nums.size();
        for(int i=0;i<len;i++)
        {
            if(count==0)res = nums[i];
            if(res == nums[i])count++;
            else count--;
        }
        return res;
    }
};