class Solution {
public:
    int Sum_Solution(int n) {
        // �ݹ顣&&�Ķ�·ԭ��
        int ans = n;
        ans && (ans += Sum_Solution(n-1));
        return ans;
    }
};
