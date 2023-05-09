/*
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

说明：解集不能包含重复的子集。

示例:

 输入： nums = [1,2,3]
 输出：
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/power-set-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subst;
        subst.push_back({});
        for(int i=0;i<nums.size();i++) {
            int size = subst.size();
            for(int j=0;j<size;j++) {
                vector<int> new_sub = subst[j];
                new_sub.push_back(nums[i]);
                subst.push_back(new_sub);
            }
        }
        return subst;
    }
};
