int hgt [100001];
int pos [100001];
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        heights.push_back(0);
        int ans=heights[0], n=heights.size(), m=0;
        hgt[0]=heights[0];
        pos[0]=0;
        for(int i=1; i<n; ++i) {
            pos[m+1]=i;
            for(; m>=0 && heights [i]<hgt[m]; --m) {
                ans=max(ans,hgt[m]*(i-pos[m]));
            }
            hgt[++m]=heights[i];
        }
        return ans;
    }
};