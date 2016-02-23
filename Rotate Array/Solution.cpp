class Solution {
public:
/*
    void rotate(vector<int>& nums, int k) {
        vector<int> n(nums);
        for(int i=0;i<nums.size();i++)
        {
            int j=(i+k)%nums.size();
            nums[j] = n[i];
        }
    }
*/
    //O(1)
    void reverse(vector<int> &nums,int begin,int end)
    {
        int tmp;
        while(begin<end)
        {
            tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(nums.size()>k)
        {
            reverse(nums,0,nums.size()-k-1);
            reverse(nums,nums.size()-k,nums.size()-1);
            reverse(nums,0,nums.size()-1);
        }
        
    }
    
};