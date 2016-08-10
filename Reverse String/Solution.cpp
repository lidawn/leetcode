class Solution {
public:
    string reverseString(string s) {
        int size = s.size();
        int i = 0;
        string ret;
        while(i<size)
        {
            ret.append(1,s[size-i-1]);
            i++;
        }
        return ret;
    }
};