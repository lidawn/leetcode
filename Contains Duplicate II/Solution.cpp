class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int size=nums.size();
        //map 键值为值，val为索引
        for(int i=0;i<size;i++)
        {
            if(m.find(nums[i])==m.end()) m[nums[i]] = i;
            else if(m[nums[i]] == i) continue;
            else
            {
                if(abs(m[nums[i]] - i)<=k)return true;
                else
                {
                    m[nums[i]] = i;
                }
            }
        }
        return false;
    }
};