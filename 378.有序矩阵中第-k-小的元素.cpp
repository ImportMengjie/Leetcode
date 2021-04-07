/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (62.79%)
 * Likes:    425
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 84.6K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
 * 请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
 * 
 * 
 * 
 * 示例：
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * 返回 13。
 * 
 * 
 * 
 * 
 * 提示：
 * 你可以假设 k 的值永远是有效的，1 ≤ k ≤ n^2 。
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:

    int check(vector<vector<int>>& matrix, const int& mid){
        int num = 0;
        int col = 0, row = matrix.size()-1;
        while (row>=0&&col<matrix[0].size()) {
            if(matrix[row][col]<=mid){
                col++;
                num += row+1;
            }else
                row--;
        }
        return num;       
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix.back().back();

        while(left<right){
            int mid = left + ((right-left)>>1);
            int num_lt_mid = check(matrix, mid);
            if(num_lt_mid<k)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};
// @lc code=end

