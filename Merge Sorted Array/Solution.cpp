class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n;
        n--;
        m--;
        while(m>=0||n>=0)
        {
            if(n==-1)return;
            if(m>=0 && nums2[n] < nums1[m])
            {
                nums1[--k] = nums1[m];
                m--;
            }
            else
            {
                nums1[--k] = nums2[n];
                n--;
            }
        }
    }
};