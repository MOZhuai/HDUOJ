#include <stdio.h>
#include <string.h>
int main(){
    int T, n, k, a[8][2];
    while (scanf("%d", &T) != EOF){
        for (int i = 0; i < T; i++){
            // init
            scanf("%d%d", &n, &k);
            for (int j = 0; j < k; j++){
                scanf("%d%d", &a[j][0], &a[j][1]);
            }
            long long int c[400], temp[400];
            memset(c, 0, sizeof(c));
            memset(temp, 0, sizeof(temp));
            // a0 -> c
            for (int j = 0; j <= a[0][1] * a[0][0]; j += a[0][0]){
                c[j] = 1;
            }
            // ai -> c
            for (int j = 1; j < k; j++){
                for (int l = 0; l <= a[j][1] * a[j][0]; l += a[j][0]){
                    for (int m = 0; m + l < 400; m++){
                        temp[m + l] += c[m];
                    }
                }
                for (int m = 0; m < 400; m++){
                    c[m] = temp[m];
                    temp[m] = 0;
                }
            }
            printf("%lld\n", c[n]);
        }
    }
}