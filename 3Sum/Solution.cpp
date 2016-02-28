class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i,j,len=nums.size(),k;
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        for(i=0;i<len-2;i++)
        {
            if(nums[i]>0)break;
            k = i+1;
            j = len-1;
            while(k<j)
            {
                if(nums[i]+nums[j]+nums[k] == 0)
                {
                    tmp.push_back({nums[i],nums[k],nums[j]});
                }
            }
            
        }
        return ret;
    }
};