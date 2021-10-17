#include <stdio.h>
#include <stdarg.h>
#define MAX 2147483647
int L, N, C, T, VR, VT1, VT2, p[150];
// 记录到第i个加电站的最小耗费时间
double dp[150];
int main(){
    while (scanf("%d", &L) != EOF) {
        // 初始化dp
        for (int i = 0; i < 150; i++){
            dp[i] = MAX;
        }
        scanf("%d%d%d%d%d%d", &N, &C, &T, &VR, &VT1, &VT2);
        double r_time = 1.0 * L / VR;
        double t_time = 0.0;
        for (int i = 1; i <= N; i++){
            scanf("%d", &p[i]);
        }
        p[0] = 0;
        p[N + 1] = L;
        dp[0] = 0;
        // 自底向上
        for (int i = 1; i <= N + 1; i++){
            // 到j加电站加电
            for (int j = 0; j < i; j++){
                // j加电站到i加电站的距离
                int remain = p[i] - p[j];
                // j加电站充电后，到i加电站的时间
                double min_flag;
                if(C > remain){
                    min_flag = 1.0 * remain / VT1 + dp[j];
                } else {
                    min_flag = 1.0 * C / VT1 + 1.0 * (remain - C) / VT2 + dp[j];
                }
                if(j){
                    min_flag = min_flag + T;
                }
                if(dp[i] > min_flag){
                    dp[i] = min_flag;
                }
            }
        }
        if(r_time <= dp[N + 1]) {
            printf("Good job,rabbit!\n");
        } else {
            printf("What a pity rabbit!\n");
        }
    }
}