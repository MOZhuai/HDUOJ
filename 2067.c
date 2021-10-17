#include <stdio.h>
int main(){
    int n, number = 1;
    __int64 a[36];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= 35; i++){
        a[i] = 0;
        for (int j = 0; j < i; j++){
            a[i] += a[j] * a[i - j - 1];
        }
    }
    while(scanf("%d", &n) != EOF){
        if(n == -1){
            break;
        }
        printf("%d %d %I64d\n", number++, n, a[n] * 2);
    }
}