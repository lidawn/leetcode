class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        for(int i=0;i<length;i++)
        {
            if(nums[i]!=0)continue;
            int k=i,backward=0;
            while(nums[k]==0)
            {
                if(k==length)break;
                backward++;
                k++;
            }
            
            if(i+backward-1==length)break;

            for(int j=0;j<backward;j++)
            {
                if(i+j+backward == length)break;
                nums[i+j] = nums[i+j+backward];
                nums[i+j+backward] = 0;
            }
            
        }
    }
 
};