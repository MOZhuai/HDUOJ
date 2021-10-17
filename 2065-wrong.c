#include <stdio.h>
int fun(int, int, int);
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(!n){
            break;
        }
        for (int l = 1; l <= n; l++){
            int length;
            scanf("%d", &length);
            int sum = fun(length, 0, 0);
            printf("Case %d: %d\n", l, sum);
        }
        printf("\n");
    }
}
// 在剩下n个位置的第一个位置填ABCD
int fun(int n, int A_sbp, int C_sbp){
    int sum = 0;
    if(n == 2 && (A_sbp + C_sbp == 2)){
        return 2;
    }
    if(n == 2 && (A_sbp + C_sbp == 1)){
        return 4;
    }
    if(n == 1 && (A_sbp + C_sbp == 1)){
        return 1;
    }
    if(n == 1 && (A_sbp + C_sbp == 0)){
        return 2;
    }
    return (fun(n - 1, 1 - A_sbp, C_sbp) + fun(n - 1, A_sbp, 1 - C_sbp) + fun(n - 1, A_sbp, C_sbp) * 2) % 100;
}