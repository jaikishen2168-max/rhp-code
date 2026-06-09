#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> grid(rows, vector<int>(cols));
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> dp(rows, vector<int>(cols));
    
    for(int i = 0; i < rows; i++){
        dp[i][0] = grid[i][0];
    }
    for(int j = 1; j < cols; j++){
        for(int i = 0; i < rows; i++){
            int best = 0;
            for(int k = 0; k < rows; k++){
                if(k != i){
                    best = max(best, dp[k][j-1]);
                }
            }
            dp[i][j] = grid[i][j] + best;
        }
    }
    int ans = 0;
    for(int i = 0; i < rows; i++){
        ans = max(ans, dp[i][cols-1]);
    }
    cout << ans << endl;
}
    
