class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        bool flag=true;
        if(strs.empty())return prefix;
        for(int i=0;i<strs[0].size();i++)
        {
            prefix.append(1,strs[0][i]);
            for(int j=1;j<strs.size();j++)
            {
                //cout<<prefix<<endl;
                if(i+1>strs[j].size()){flag=false;break;}
                if(strs[j].compare(0,i+1,prefix)){flag=false;break;}
            }
            if(flag==false)return prefix.substr(0,i);
        }
        return prefix;
    }
};