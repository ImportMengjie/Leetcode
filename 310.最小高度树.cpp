/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 *
 * https://leetcode-cn.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (33.90%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 24.5K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * 
 * 对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。
 * 
 * 格式
 * 
 * 该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。
 * 
 * 你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。
 * 
 * 示例 1:
 * 
 * 输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 * 
 * ⁠       0
 * ⁠       |
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3 
 * 
 * 输出: [1]
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 * 
 * ⁠    0  1  2
 * ⁠     \ | /
 * ⁠       3
 * ⁠       |
 * ⁠       4
 * ⁠       |
 * ⁠       5 
 * 
 * 输出: [3, 4]
 * 
 * 说明:
 * 
 * 
 * 根据树的定义，树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
 * 树的高度是指根节点和叶子节点之间最长向下路径上边的数量。
 * 
 * 
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> graph(n,vector<int>());
        vector<int> indegree(n,0);
        for(auto& edge:edges){
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==1) q.push(i);
        while(n>2){
            int len = q.size();
            n-=len;
            for(int i=0;i<len;i++){
                int v = q.front();
                q.pop();
                indegree[v] = 0;
                for(auto& a:graph[v]){
                    indegree[a]--;
                    if(indegree[a]==1)
                        q.push(a);
                }
            }
        }
        vector<int> ans;
        while (q.size()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

