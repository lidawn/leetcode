class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if(size%2)return false;
        stack<char> st;
        int i=0;
        for(i=0;i<size;i++)
        {
            if(!st.empty())
            {
                if(s[i]==')'&&st.top()=='(')st.pop();
                else if(s[i]==']'&&st.top()=='[')st.pop();
                else if(s[i]=='}'&&st.top()=='{')st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        if(st.empty())return true;
        else return false;
    }
};