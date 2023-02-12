class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int n=cardPoints.size();
        int i=0,j=n-1;
        int sum=0;
        for(i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        i--;
        if(n==k) return sum;
       
        ans=max(ans,sum);
        while(j>=n-k && i>=0){
            
            sum+=cardPoints[j--];
            sum-=cardPoints[i--];
            
            ans=max(ans,sum);
        }
        return ans;
    }
};