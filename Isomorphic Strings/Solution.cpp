class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char> m;
       unordered_map<char,char> n;
       int size_s = s.size();
       int size_t = t.size();
       if(size_t==0 && size_s==0)return true;
       if(size_s == size_t)
       {
           for(int i=0;i<size_s;i++)
           {
               if(m.find(s[i]) == m.end())m[s[i]] = t[i];
               else 
               {
                   if(m[s[i]] != t[i]) return false;
               }
               if(n.find(t[i]) == n.end())n[t[i]] = s[i];
               else 
               {
                   if(n[t[i]] != s[i]) return false;
               }
           }
           return true;
       }
       else return false;
    }
};