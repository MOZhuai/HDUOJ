#include <stdio.h>
#include <string.h>
int coins[5] = {1, 5, 10, 25, 50};
// dp[j][k]:k个硬币组成j元的方法数
long long int dp[251][101];
int main(){
    //初始化dp
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < 5; i++){
        // k个硬币
        for (int k = 1; k <= 100; k++){
            for (int j = coins[i]; j <= 250; j++){
                // dp[j][k]为尚未使用coins[i~n-1]的钞票
                // dp[j - coins[i]][k - 1]为加上使用面值为coins[i]的方法数
                // 减 coins[i]表示至少用一个该硬币
                dp[j][k] += dp[j - coins[i]][k - 1];
            }
        }
    }
    int n;
    while (scanf("%d", &n) != EOF){
        long long int sum = 0;
        for (int i = 0; i <= 100; i++){
            sum += dp[n][i];
        }
        printf("%lld\n", sum);
    }
}