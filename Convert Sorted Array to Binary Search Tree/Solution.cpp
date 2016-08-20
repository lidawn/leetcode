/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //不包括end
    TreeNode* build(vector<int>& nums,int start,int end)
    {
        if(start==end)return NULL;
        int mid = (start+end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums,start,mid);
        root->right = build(nums,mid+1,end);
        return root;        
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size==0) return NULL;
        else return build(nums,0,size);
    }
};