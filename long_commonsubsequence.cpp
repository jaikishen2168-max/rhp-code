#include <iostream>
using namespace std;

int main() {
string s1,s2;
    cin>>s1;
    cin>>s2;
    int a=s1.length();
    int b=s2.length();
    int dp[a+1][b+1];
    for (int i = 0; i <= a; i++){
        dp[i][0] = 0;
    }
    for (int j = 0; j <= b; j++){
        dp[0][j] = 0;
    }
    for (int row=1;row<=a;row++){
        for(int col=1;col<=b;col++){
            if(s1[row-1]==s2[col-1]){
                dp[row][col]=1+dp[row-1][col-1];
            } else {
                dp[row][col] = max(dp[row - 1][col],dp[row][col - 1]);
            }
        }
    }
    cout<<dp[a][b];
    return 0;
}
