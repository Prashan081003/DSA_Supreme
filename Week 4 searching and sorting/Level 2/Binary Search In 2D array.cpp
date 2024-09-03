// Leetcode 74 (Medium)
//binary search in a  2D matrix 

// <<<<<<<<<<========= Formula of conversion of  1D to 2D and 2D to 1D ===============>>>>>>>

       //2D-1D ====> int index  =   no.of columns* no. of rows  + j(column ka index)  ;
       //1D-2D  ====>  int RowIndex  =  mid/column  ; int ColIndex = mid % column;
                        
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col;

        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) {
            int rowIndex = mid/col;
            int colIndex = mid % col;
            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber == target)
                return true;
            else if(target > currNumber ) {
                //right;
                s = mid + 1;
            } 
            else {
                //left;
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return false;
    }
};
