#include <stdio.h>
#include <string.h>
#define inf 10000
int max(int, int);
int min(int, int);
int d[1001][1001], time, a, b, n;
int main(){
    int T, S, D;
    while(scanf("%d%d%d", &T, &S, &D) != EOF){
        // 初始化
        n = 0;
        for (int i = 0; i < 1001; i++){
            for (int j = 0; j < 1001; j++){
                if(i == j) {
                    d[i][j] = 0;
                } else {
                    d[i][j] = inf;
                }
            }
        }
        // 输入所有路径
        for (int i = 0; i < T; i++){
            scanf("%d%d%d", &a, &b, &time);
            if(d[a][b] > time){
                d[a][b] = d[b][a] = time;
                n = max(n, max(a, b));
            }
        }
        // 输入家附近的地方
        for (int i = 0; i < S; i++){
            scanf("%d", &a);
            d[0][a] = 0;
            d[a][0] = 0;
        }
        // floyd
        for (int k = 0; k < n + 1; k++){
            for (int i = 0; i < n + 1; i++){
                if(d[i][k] != inf) {
                    for (int j = 0; j < n + 1; j++){
                        if(d[k][j] != inf){
                            d[i][j] = d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                        }
                    }
                }
            }
        }
        int min = inf;
        for (int i = 0; i < D; i++){
            scanf("%d", &a);
            if(min > d[0][a]){
                min = d[0][a];
            }
        }
        printf("%d\n", min);
    }
}
int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}