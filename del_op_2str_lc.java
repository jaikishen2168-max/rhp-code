class Solution {
    public int minDistance(String word1, String word2) {
        int R=word1.length();
        int C=word2.length();

        int dp[][]=new int[R+1][C+1];
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (R-dp[R][C])+(C-dp[R][C]);
    }
}
