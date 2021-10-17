#include <stdio.h>
#include <math.h>
int main(){
    int n, b[21];
    long long int m;
    long long int a[21];
    a[0] = 0;
    a[1] = 1;
    while(scanf("%d%lld", &n, &m) != EOF){
        b[0] = 0;
        b[1] = 1;
        int i;
        for (i = 2; i <= n; i++){
            a[i] = i * (1 + a[i - 1]);
            b[i] = i;
        }
        long long int remain = m;
        int row = (int)ceil(1.0 * remain / (a[n - 1] + 1));
        printf("%d", b[row]);
        for (int j = row; j < n; j++){
            b[j] = b[j + 1];
        }
        remain = remain - (row - 1) * ((a[n - 1] + 1)) - 1;
        for (i = 1; remain != 0; i++){
            row = (int)ceil(1.0 * remain / (a[n - i - 1] + 1));
            printf(" %d", b[row]);
            for (int j = row; j < n - i; j++){
                b[j] = b[j + 1];
            }
            remain = remain - (row - 1) * ((a[n - i - 1] + 1)) - 1;
        }
        printf("\n");
    }
}