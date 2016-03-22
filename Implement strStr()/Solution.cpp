class Solution {
public:
    /*即kmp*/
    void getNext(string &s,int &len,vector<int> &next)
    {
        int k=-1,j=0;
        while(j<len-1)
        {
            if(k==-1 || s[j] == s[k])
            {
                k++;
                j++;
                next[j] = k;
            }
            else k = next[k];
        }
    }
    int strStr(string haystack, string needle) {
        int lenh = haystack.size();
        int lenn = needle.size();
        if(lenn==0)return 0;
        if(lenn > lenh)return -1;
        
        vector<int> next(lenn,-1);
        getNext(needle,lenn,next);
        cout<<next[0];
        int i=0,j=0;
        while(i<lenh&&j<lenn)
        {
            if(j==-1 ||haystack[i]==needle[j])
            {
                j++;
                i++;
            }
            else
            {
                j = next[j];
            }
        }
        if(j==lenn)return i - j;
        else return -1;
    }
};