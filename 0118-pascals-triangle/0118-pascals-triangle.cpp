// M-1 (Doing simply just like Pascal triangle is formed)
// for returning only 1 row we can space optimise it 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i = 0; i<numRows; i++) {
            result[i] = vector<int>(i+1, 1);
            for(int j = 1; j < i; j++)
                result[i][j] = result[i-1][j] + result[i-1][j-1];   
        }
        return result;
    }
};


// M-2 (Using simple math formula) (Striver)
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         long long ans=1;
//         vector<int>res;
//         res.push_back(ans);
//         for (int i = 1; i < rowIndex+1; i++) {
//             ans = ans * (rowIndex+1 - i);
//             ans = ans / i;
//             res.push_back(ans);
//         }
//         return res;
//     }
    
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> result;
//         result.push_back({1});
//         if(numRows == 1)
//             return result;
//         for(int lineNo = 1; lineNo < numRows; lineNo++)
//             result.push_back(getRow(lineNo));
//         return result;
//     }
// };


// M-3 striver (using generating 1 element)
// class Solution{
// public:
//     int nCr(int n, int r) {
//         long long res = 1;
//         for (int i = 0; i < r; i++) {
//             res = res * (n - i);
//             res = res / (i + 1);
//         }
//         return res;
//     }
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> triangle;
//         for (int n = 0; n < numRows; n++) {
//             vector<int> row;
//             for (int r = 0; r <= n; r++)
//                 row.push_back(nCr(n, r));
//             triangle.push_back(row);
//         }
//         return triangle;
//     }
// };




// To print 1 element - 
// int nCr(int n, int r) {
//     long long res = 1;
//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// int pascalTriangle(int r, int c) {
//     int element = nCr(r - 1, c - 1);
//     return element;
// }