class Solution {
public:
    
    vector<int> getRow(int rowIndex) {
        vector<int> a(rowIndex+1,0);
        a[0] = 1;
        for(int i=1;i<rowIndex+1;i++)
            for(int j=i;j>0;j--)
                a[j] = a[j-1]+a[j];
        return a;
    }
};