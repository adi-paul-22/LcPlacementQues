class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) {
        
        vector<int> modCount(K, 0);
        modCount[0] = 1;
        int sum = 0, ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % K;
            if (sum < 0) sum += K;
            ans += modCount[sum]++;
        }
        
        return ans;
    }
};