/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 *
 * https://leetcode-cn.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (42.91%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 16.6K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 
 * 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
 * 
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 * 
 * 说明:
 * 
 * 
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。       
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string fillwords(vector<string> &words, int start, int end, int maxWidth, bool is_last_line)
    {
        int word_count = end - start + 1;
        int space_count = maxWidth + 1 - word_count;
        for (int i = start; i <= end; i++)
            space_count -= words[i].size();
        int space_avg = (word_count == 1) ? 1 : space_count / (word_count - 1);
        int space_extra = word_count == 1 ? 0 : space_count % (word_count - 1);
        string ans;
        for (int i = start; i < end; i++)
        {
            ans += words[i];
            if (is_last_line)
                fill_n(back_inserter(ans), 1, ' ');
            else
                fill_n(back_inserter(ans), 1 + space_avg + ((i - start) < space_extra), ' ');
        }
        ans += words[end];
        fill_n(back_inserter(ans), maxWidth - ans.size(), ' ');
        return ans;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int start = 0, count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            count += words[i].size() + 1;
            if (i + 1 == words.size() || count + words[i + 1].size() > maxWidth)
            {
                ans.push_back(fillwords(words, start, i, maxWidth, i + 1 == words.size()));
                count = 0;
                start = i + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
