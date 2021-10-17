#include <stdio.h>
#include <string.h>
int find(int);
int boy[501], used[501];
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
            memset(used, 0, sizeof(used));
            sum += find(i);
        }
        printf("%d\n", sum);
    }
    
}
int find(int x){
    for (int i = 1; i <= n; i++){
        if(a[x][i] == 1 && !used[i]){
            used[i] = 1;
            if(boy[i] == 0 || find(boy[i])){
                boy[i] = x;
                return 1;
            }
        }
    }
    return 0;
}