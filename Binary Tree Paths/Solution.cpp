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
    void printPath(TreeNode *node,string s, vector<string> &ret)
    {
        if(node)
        {
            if(s.empty())
            {
                s+=to_string(node->val);
            }
            else
            {
                s+="->";
                s+=to_string(node->val);
            }
            printPath(node->left,s,ret);
            printPath(node->right,s,ret);
            if(node->right==NULL&&node->left==NULL)ret.push_back(s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        /*
        vector<string> ret;
        stack<TreeNode*> st;
        if(root)st.push(root);
        TreeNode *tmp;
        vector<string>::iterator it;
        while(!st.empty())
        {
            int pushed = 0;
            tmp = st.top();
            
            if(ret.size()==0)
            {
                string s1;
                s1=to_string(tmp->val);
                ret.push_back(s1);
                it = ret.begin();
            }
            else
            {
                string &s2=*it;
                s2+="->";
                s2+=to_string(tmp->val);
                //*it = s2;
            }
            
            st.pop();
            if(tmp->right){st.push(tmp->right);pushed++;}
            if(tmp->left){st.push(tmp->left);pushed++;}
            //有两个节点，则复制一份字符串
            if(pushed==2)
            {
                string s3(*it);
                //返回插入元素的迭代器，这里貌似一定要更新这个迭代器
                it = ret.insert(it+1,s3);
                it--;
            }
            
            //没有子树，迭代器后移
            else if(pushed==0)it++;
        }
        return ret;
        */
        //递归解法
        vector<string> ret;
        string s;
        if(root)printPath(root,s,ret);
        return ret;
    }

};