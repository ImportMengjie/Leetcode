# 算法总结

## 数据结构

### 比较

1. less<>

    ```c++
    template <>
    struct less<void>
    {
        template <class _T1, class _T2>
        auto operator()(_T1&& __t, _T2&& __u) const -> decltype        (_VSTD::forward<_T1>(__t) < _VSTD::forward<_T2>(__u)) { 
                return  _VSTD::forward<_T1>(__t) < _VSTD::forward<_T2>(__u); 
        }
        typedef void is_transparent;
    };
    ```

2. greater<> // 用于排序则是降序

    ```c++
    struct  greater : binary_function<_Tp, _Tp, bool>
    {
        _LIBCPP_CONSTEXPR_AFTER_CXX11 _LIBCPP_INLINE_VISIBILITY
        bool operator()(const _Tp& __x, const _Tp& __y) const
            {return __x > __y;}
    };
    ```

### 优先队列 (priority_queue)

1. 默认比较(大顶堆)

    ```c++
    priority_queue<int> pq;
    priority_queue<int, vector<int>, less<int> > pq;
    ```

2. 小顶堆

    ```c++
    priority_queue<int, vector<int>, greater<int> > pq
    ```

3. 自定义

    ```c++
    struct comp {
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val < l2->val;
        }
    };
    priority_queue<ListNode*, vector<ListNode*>, comp> pq; // 大顶堆
    ```

## 算法专题

### 排列组合

#### 排列组合公式

1. 公式A, 从N个元素中取出M个进行排列的个数
   $$
   A_n^m=\frac{n!}{(n-m)!}
   $$
2. 公式C, 从N个元素中取出M个元素进行组合的个数
   $$
   C_n^m=\frac{A_n^m}{m!}=\frac{n!}{m!(n-m)!}
   $$

#### DFS遍历法

```c++
// 子集=>N个数, 取0个/1个/.../N个数的组合
void backtrack(vector<vector<int>>& ans,vector<int>& nums, vector<int>&& path, int start){
    ans.push_back(path);
    for(int i=start;i<nums.size();i++) {
        path.push_back(nums[i]);
        backtrack(ans, nums, std::move(path), i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsets1(vector<int>& nums) {
    vector<vector<int>> ans;
    backtrack(ans, nums, {}, 0);
    return ans;
}

//排列=>N个数, 排列
void backtrack(vector<vector<int>>& ans,vector<int>& nums, vector<int>&& path, set<int>&& pick){
    if(path.size()==nums.size()) {
        ans.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++) {
        if(!pick.count(nums[i])){
            path.push_back(nums[i]);
            pick.insert(nums[i]);
            backtrack(ans, nums, std::move(path), std::move(pick));
            path.pop_back();
            pick.erase(nums[i]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtrack(ans, nums, {}, {});
    return ans;
}

//组合=>从n个数中选出k个数
void backtrack(vector<vector<int>>& ans, vector<int>&& path, int k, int n, int start){
    if(path.size()==k){
        ans.push_back(path);
        return;
    }
    for(int i=start;i<n;i++) {
        path.push_back(i+1);
        backtrack(ans, std::move(path), k, n, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    backtrack(ans, {}, k, n, 0);
    return ans;
}
//组合选数=>从n个数中选k个数合为target, 可重复选
void backtrack(vector<vector<int>>& ans,vector<int>& nums, vector<int>&& path, int start, int target){
    if(target==0){
        ans.push_back(path);
        return;
    }
    if(target<0) return;
    for(int i=start;i<nums.size();i++) {
        path.push_back(nums[i]);
        target -= nums[i];
        backtrack(ans, nums, std::move(path), i, target);
        path.pop_back();
        target += nums[i];
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    backtrack(ans, candidates, {}, 0, target);
    return ans;
}
```

### 二分查找

#### src

```c++
// 标准二分查找
int search(vector<int>& nums, int target) {
    int left=0, right = nums.size();
    while(left<right) {
        int mid = left + (right-left)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) left = mid+1;
        else right = mid;
    }
    return -1;
}
// 旋转=>查找target
bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left<=right) {
        int mid = left + (right-left)/2;
        if(nums[mid] == target) return true;
        if(nums[left]==nums[mid]){
            left++;
            continue;
        }
        if(nums[left]<=nums[mid]) { // left=>mid 连续不减
            if(nums[left]<=target && target < nums[mid]) right = mid -1;
            else left = mid + 1;
        } else {
            if(nums[mid] < target && target <= nums[right]) left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}
// 旋转=>查找最小值
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left<=right) {
        int mid = left + (right-left)/2;
        if(nums[mid]<nums[right]) right = mid;
        else if (nums[mid]>nums[right]) left = mid + 1;
        else right--;
    }
    return nums[left];
}
// 查找target第一个出现的位置和最后一个位置
vector<int> searchRange1(vector<int>& nums, int target) {
    //查找大于等于target的第一个index
    auto lowerbound = [](vector<int>& nums, int target)->int{
        int left = 0, right = nums.size() - 1, ans = nums.size();
        while(left<=right) {
            int mid = left + (right - left)/2;
            if(nums[mid]>=target) {
                right = mid - 1;
                ans = mid;
            } else left = mid + 1;
        }
        return ans;
    };
    int lower_idx = lowerbound(nums, target);
    if(lower_idx>=nums.size()||nums[lower_idx]!=target) return {-1, -1};
    int upper_idx = lowerbound(nums, target+1) - 1;
    return {lower_idx, upper_idx};
}
```
