#include <stdio.h>
#include <string.h>
int find(int, int);
int boy[501];
int k, m, n;
int a[501][501];
int main(){
    while(scanf("%d", &k) != EOF){
        if(!k){
            break;
        }
        scanf("%d%d", &m, &n);
        memset(a, 0, sizeof(a));
        memset(boy, 0, sizeof(boy));
        int x, y;
        for (int i = 0; i < k; i++){
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
        }
        int sum = 0;
        for (int i = 1; i <= m; i++){
            sum += find(i, 1);
        }
        printf("%d\n", sum);
    }
    
}
int find(int x, int y){
    for (int i = y; i <= n; i++){
        if(a[x][i] == 1){
            if(boy[i] == 0 || find(boy[i], i + 1)){
                boy[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
// 错误测试
// 7 5 5
// 1 1
// 2 1
// 2 3
// 2 4
// 4 3
// 4 5
// 5 4