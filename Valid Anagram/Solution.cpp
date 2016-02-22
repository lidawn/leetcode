class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26,0);
        int len_s = s.length();
        int len_t = t.length();
        int i = 0;
        if(len_s != len_t)return false;
        for(i=0;i<len_s;i++)a[s[i]-'a']++;
        for(i=0;i<len_t;i++)a[t[i]-'a']--;
        i=0;
        while(i<26)
        {
            if(a[i]!=0)return false;
            i++;
        }
        return true;
    }
};