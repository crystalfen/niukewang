class Solution {
public:
    int Sum_Solution(int n) {
        // 递归。&&的短路原则
        int ans = n;
        ans && (ans += Sum_Solution(n-1));
        return ans;
    }
};
