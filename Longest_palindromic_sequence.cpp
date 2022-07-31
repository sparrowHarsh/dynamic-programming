/**
*    Coded by :  Harsh vardhan 
**/

int LPS(string &s,int i,int  j,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==s[j]){
            if(i!=j){
                return dp[i][j]=2+LPS(s,i+1,j-1,dp);
            }else{
                return dp[i][j]=1+LPS(s,i+1,j-1,dp);
            }
        }else{
            int left=LPS(s,i+1,j,dp);
            int right=LPS(s,i,j-1,dp);
            
            return dp[i][j]=max(left,right);
        }
}

// Second method
// Logic -> Longest Palindromic subsequence length  nothing but the longest common subsequence length of string s and reverse of s

// implement the code of finding the lcs
