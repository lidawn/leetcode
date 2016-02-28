class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int i,j,len=nums.size(),k;
        std::sort(nums.begin(),nums.end());
        int sum=0,closet=nums[0]+nums[1]+nums[len-1];
        for(i=0;i<len-2;i++)
        {
            k=i+1;
            j = len-1;
            while(k<j)
            {
                sum =nums[i]+nums[j]+nums[k];
                if(sum == target)return sum;
                //更接近
                if(abs(sum - target) < abs(closet-target))closet = sum;
                if(sum>target)j--;
                else k++;
            
                
            }
        }
        return closet;
    }
};
