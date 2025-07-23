// M-1 Using simple Maths formula 
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         long long prev = 1;
//         vector<int> temp{1};
//         for(int i = 1; i<rowIndex+1; i++) {
//             long long curr = ((rowIndex-i+1) * prev)/i;
//             temp.push_back(curr);
//             prev = curr;
//         }
//         return temp;
//     }
// };

//M-2 (Using the same code of Pascal's Triangle-I_
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<vector<int>> result(rowIndex+1);
//         for(int i = 0; i<rowIndex+1; i++) {
//             result[i] = vector<int>(i+1, 1);
//             for(int j = 1; j < i; j++)
//                 result[i][j] = result[i-1][j] + result[i-1][j-1];
//             if(i == rowIndex) //Just return when you find rowIndex
//                 return result[i];
//         }
//         return {};
//     }
// };

//M-3 (Using less space from M-2 above)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        for(int i = 0; i<rowIndex+1; i++) {
            vector<int> curr = vector<int>(i+1, 1);
            for(int j = 1; j < i; j++)
                curr[j] = prev[j] + prev[j-1];
            prev = curr;
        }
        return prev;
    }
};