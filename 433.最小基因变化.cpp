/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 *
 * https://leetcode.cn/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (55.26%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    44.8K
 * Total Submissions: 81.2K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
 * 
 * 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
 * 
 * 
 * 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
 * 
 * 
 * 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。
 * 
 * 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end
 * 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
 * 
 * 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：start = "AACCGGTT", end = "AAACGGTA", bank =
 * ["AACCGGTA","AACCGCTA","AAACGGTA"]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：start = "AAAAACCC", end = "AACCCCCC", bank =
 * ["AAAACCCC","AAACCCCC","AACCCCCC"]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * start.length == 8
 * end.length == 8
 * 0 <= bank.length <= 10
 * bank[i].length == 8
 * start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成
 * 
 * 
 */
#include <string>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:

    bool oneStep(const string& s1, const string& s2){
        int mutations = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                mutations++;
            if(mutations>1)
                return false;
        }
        return true;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        vector<vector<int>> adj(bank.size());
        queue<int> qu;
        vector<bool> visited(bank.size(),false);
        int endIndex = -1;
        for(int i=0;i<bank.size();i++){
            if(bank[i]==end)
                endIndex = i;
            for(int j=i+1;j<bank.size();j++){
                if(oneStep(bank[i],bank[j])){
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
            if(oneStep(bank[i],start))
                qu.push(i);
        }
        if(endIndex==-1) return -1;
        int step = 1;
        while(qu.size()){
            int sz = qu.size();
            for(int i=0;i<sz;i++){
                int curr = qu.front();
                if(curr==endIndex)
                    return step;
                qu.pop();
                for(int& next:adj[curr]){
                    if(!visited[next]){
                        visited[next] = true;
                        qu.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

