class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int tot = 0,i=0;
        for(i=0;i<len;i++)
        {
            if(nums[i]==val)tot++;
            else nums[i-tot] = nums[i];
        }
        return len-tot;
    }
};