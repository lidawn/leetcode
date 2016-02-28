class Solution {
public:

/*
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int i,j;
        vector<int> result;
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    result = {i,j};
                    return result;
                }
            }
        }
    }
 */   
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int i;
        vector<int> result;
        unordered_map<int,int> m;
        for(i=0;i<len;i++)
        {
            if(m.find(target - nums[i])!=m.end() )
            {
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
    }
};