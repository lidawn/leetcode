class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int jin = 1;
        int i = digits.size()-1;
        while(jin)
        {
            if(i<0)break;
            int t = digits[i] +jin;
            digits[i] = t % 10;
            jin = t / 10;
            i--;
        }
        if(jin)digits.insert(digits.begin(),jin);
        return digits;
    }
};