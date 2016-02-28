class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int i,j,len=nums.size(),k;
        std::sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[len-1];
        for(i=0;i<len-2;i++)
        {
            k=i+1;
            j = len-1;
            while(k<j)
            {
                if(sum == nums[i]+nums[j]+nums[k])
                {
                    //
                    if(sum<target)k++;
                    else if(sum>target)j--;
                    else return sum;
                }
                else if(sum < nums[i]+nums[j]+nums[k])
                {
                    //更大更接近
                    if(abs(nums[i]+nums[j]+nums[k] - target) < abs(sum-target))
                    {
                        sum = nums[i]+nums[j]+nums[k];
                        k++;
                    }
                    else j--;
                }
                else
                {
                    //更小更接近
                    if(abs(nums[i]+nums[j]+nums[k] - target) < abs(sum-target))
                    {
                        sum = nums[i]+nums[j]+nums[k];
                        j--;
                    }
                    else k++;
                }
                /*
                if((nums[i]+nums[j]+nums[k] - target) >= (sum-target))break;
                else
                {
                    sum = nums[i]+nums[j]+nums[k];
                    k++;
                }
                */
                
            }
        }
        return sum;
    }
};
