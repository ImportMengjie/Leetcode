/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (43.95%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 36.6K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 * 
 * 编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 */
#include <string>
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> output, seen;
        vector<string> ans;
        if(s.size()>10)
            for(int i=10;i<=s.size();i++)
                if(seen.count(s.substr(i-10, 10)))
                    output.insert(s.substr(i-10,10));
                else
                    seen.insert(s.substr(i-10,10));
        ans.assign(output.begin(), output.end());
        return ans;
    }
};
// @lc code=end

