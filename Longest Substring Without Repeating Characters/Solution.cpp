class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //三个信息
        int start=0;//substring 起始位置
        int end=0;//substring 结束位置
        int length=1;//当前最长长度
        if(s.size()==0 || s.size()==1)return s.size();
        else start=end=0;
        for(int i=1;i<s.size();i++)
        {
            int j=start;
            for(j=start;j<=end;j++)
            {
                if(s[i]!=s[j])continue;
                else break;
            }
            if(j==i)end++;
            else
            {
                end++;
                start = j+1;
            }
            if(length < (end-start+1))length=end-start+1;
        }
        return length;
    }
};