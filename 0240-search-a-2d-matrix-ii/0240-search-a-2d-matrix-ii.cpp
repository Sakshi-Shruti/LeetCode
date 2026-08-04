class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        int row = 0; int col = n-1;
        while(row < m && col >= 0) { //It is for the iteration when we take 15 as our mid
            if(target == matrix[row][col]) {
                return true;
            } else if(target < matrix[row][col]) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};