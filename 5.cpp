class Solution {
public:
    int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
        
        if (end - begin <= 1)
            return 0;
        auto mid = begin + (end - begin) / 2;
        int count = sort_and_count(begin, mid) + sort_and_count(mid, end);
        for (auto i = begin, j = mid; i != mid; ++i) {
            while (j != end and *i > 2LL * *j)//注意，long在这里是8位和32位vs不同
                ++j;
            count += j - mid;
        }
        inplace_merge(begin, mid, end);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        cout<<sizeof(long)<<endl;
        cout<<sizeof(long long)<<endl;
        return sort_and_count(nums.begin(), nums.end());
    }
};