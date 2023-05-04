/*
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/zero-matrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0=false, row0=false;
        int m = matrix.size();
        int n= matrix.back().size();
        for(int row=0;row<m;row++)
            if(!matrix[row][0])
                row0 = true;
        for(int col=0;col<n;col++)
            if(!matrix[0][col])
                col0 = true;
        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                if(!matrix[row][col]){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                if(!matrix[row][0]||!matrix[0][col])
                    matrix[row][col] = 0;
            }
        }
        if(row0){
            for(int row=0;row<m;row++)
                matrix[row][0] = 0;
        }
        if(col0){
            for(int col=0;col<n;col++)
                matrix[0][col] = 0;
        }
    }
};
