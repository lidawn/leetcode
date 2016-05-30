class Solution {
public:
    int reverse(int x) {
        int ret=0;
        while(x/10)
        {
            ret *=10;
            ret += x%10;
            x /= 10;
        }
        if(ret>0&&INT_MAX/10 < ret)return 0;
        if(ret<0&&INT_MIN/10 > ret)return 0;
        if(x!=0)ret *=10;
        ret += x%10;
        return ret;
    }
};