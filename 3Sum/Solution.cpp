class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i,j,len=nums.size(),k;
        
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        int sum=0;
        if(len<3)return ret;
        for(i=0;i<len-2;i++)
        {
            
            //i增加之前，后面的所有情况都遍历过了
            if(nums[i]>0)break;
            k=i+1;
            if(i>0&&nums[i]==nums[i-1])continue;
            j = len-1;
            if(nums[j]<0)break;
            //判断是否重复
            
            while(k<j)
            {
                if(k-i>1&&nums[k]==nums[k-1])
                {
                    k++;
                    continue;
                }
                sum = nums[i]+nums[j]+nums[k];
                if(sum == 0)
                {
                    
                    tmp.clear();
                    tmp = {nums[i],nums[k],nums[j]};
                    ret.push_back(tmp);
                    k++;
                    j--;
                }
                else if(sum < 0)k++;
                else j--;
            }
        }
        return ret;
    }
};