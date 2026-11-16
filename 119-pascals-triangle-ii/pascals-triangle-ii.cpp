class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize an array of size (rowIndex + 1) with all 0s
        vector<int> row(rowIndex + 1, 0);
        
        // The first element of any row in Pascal's triangle is always 1
        row[0] = 1;
        
        // Build the rows one by one up to rowIndex
        for (int i = 1; i <= rowIndex; i++) {
            // Update the row from right to left to avoid overwriting needed values
            for (int j = i; j >= 1; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};