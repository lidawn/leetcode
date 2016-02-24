class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())return 0;
        int flag = nums[0];
        int i=0,same = 0,len = nums.size();
        for(i=0;i<len;i++)
        {
            
            if(nums[i]==flag)same++;
            else
            {
                flag = nums[i];
                same -= 1;
                nums[i-same] = nums[i];
                i--;
            }
        }
        return len-same+1;
    }
};