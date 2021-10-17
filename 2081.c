#include <stdio.h>
#include <string.h>
int main(){
    int T, x[27];
    while (scanf("%d", &T) != EOF){
        for (int i = 0; i < T; i++){
            // init
            for (int j = 1; j <= 26; j++){
                scanf("%d", &x[j]);
            }
            long long int c[400], temp[400];
            memset(c, 0, sizeof(c));
            memset(temp, 0, sizeof(temp));
            // a0 -> c
            for (int j = 0; j <= x[1]; j ++){
                c[j] = 1;
            }
            // ai -> c
            for (int j = 2; j <= 26; j++){
                for (int l = 0; l <= x[j] * j; l += j){
                    for (int m = 0; m + l <= 50; m++){
                        temp[m + l] += c[m];
                    }
                }
                for (int m = 0; m <= 50; m++){
                    c[m] = temp[m];
                    temp[m] = 0;
                }
            }
            long long int sum = 0;
            for (int j = 1; j <= 50;j++){
                sum += c[j];
            }
            printf("%lld\n", sum);
        }
    }
}