class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        vector<int> row(1,1);
        if(numRows>0)
        {
            pt.push_back(row);
        }
        if(numRows>1)
        {
            vector<int> row_n(row);
            row_n.push_back(1);
            pt.push_back(row_n);
        }
        for(int i=2;i<numRows;i++)
        {
            vector<int> row_n(row);
            for(int j=1;j<i;j++)
                row_n.push_back(pt[i-1][j-1]+pt[i-1][j]);
            row_n.push_back(1);
            pt.push_back(row_n);
        }
        return pt;
        
    }
};