class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        string ret;
        int zigsize = 2 * nRows - 2,len=s.size();
        for(int i=0;i<nRows;i++)
        {
            for(int base=i;base<len;base+=zigsize)
            {
                ret.append(1,s[base]);
                if(i!=0&&i!=nRows-1)
                {
                    int t = base+zigsize-2*i;
                    if(t<len)ret.append(1,s[t]);
                }
            }
        }
        return ret;
    }
};