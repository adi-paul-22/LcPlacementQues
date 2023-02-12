class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // checks if the first row contains a zero
        for(int j=0;j<n;j++){
            if(matrix[0][j] == 0){
                firstRowZero = true;
                break;
            }
        }
        // checks if the first column contains a zero
        for(int i =0;i<m;i++){
            if(matrix[i][0] == 0){
                firstColZero = true;
                break;
            }
        }
        // use the first row and column as markers for the rest of the matrix
        for(int i=1;i<m;i++){
            for(int j =1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // nullify rows based on markers in first column
        for(int i = 1;i<m;i++){
            if(matrix[i][0] == 0){
                for(int j = 1;j<n;j++){
                    matrix [i][j] = 0;
                }
            }
        }
        // nullify columns based on markers in first row
        for(int j=1;j<n;j++){
            if(matrix[0][j] == 0){
                for(int i=1;i<m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        // nullify the first row if it had a zero
        if(firstRowZero){
            for(int j=0;j<n;j++){
                matrix[0][j] = 0;
            }
        }
        // nullify the first column if it had a zero
        if(firstColZero){
            for(int i=0;i<m;i++){
                matrix[i][0] =0;
            }
        }
    }
};