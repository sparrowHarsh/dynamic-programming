/*
** coded by : Harsh Vardhan
*/

int lengthOfLIS(vector<int>& v) { 
        int n=v.size();
        vector<int> dp(n+1,1);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(v[j]<v[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
        int ans=*max_element(dp.begin(),dp.end());
        
        return ans;
 }
