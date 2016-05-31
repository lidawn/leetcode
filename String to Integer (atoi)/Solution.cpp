

class Solution {
public:
    int myAtoi(string str) {
        bool zheng = true;
        int ret=0;
        string::iterator i = str.begin();
        for(; i!=str.end();i++)
        {
            if(*i==' ')continue;
            else break;
        }
        if(i==str.end())return 0;
        if(!(*i=='+' || *i=='-' || isLegal(*i))) return 0;
        if(*i == '-'||*i=='+'){zheng=(*i == '-')?false:true;i++;}
        if(i==str.end()||!isLegal(*i))return 0;
        
        //if(i==str.end()-1)return (isLegal(*i) ? *i-'0':0);
        
       for(; i!=(str.end()-1);i++)
        {
            
            if(isLegal(*i))
            {
                if(zheng&&INT_MAX/10 < ret)return INT_MAX;
                if(!zheng&&INT_MIN/10 > -ret)return INT_MIN;
                ret *= 10;
                if(zheng&&INT_MAX-ret < (*i - '0') )return INT_MAX;
                if(!zheng&&INT_MIN+ret > -(*i - '0') )return INT_MIN;
                ret += (*i - '0');
            }

            else break;
        }
        
        if(isLegal(*i))
        {
            if(zheng&&INT_MAX/10 < ret)return INT_MAX;
            if(!zheng&&INT_MIN/10 > -ret)return INT_MIN;
            ret *= 10;
            if(zheng&&INT_MAX-ret < (*i - '0') )return INT_MAX;
            if(!zheng&&INT_MIN+ret > -(*i - '0') )return INT_MIN;
            ret += (*i - '0');
        }

        if(!zheng)return 0-ret;
        else return ret;
    }

    bool isLegal(char c)
    {
        if(c<='9' && c>='0')return true;
        else return false;
    }
};

