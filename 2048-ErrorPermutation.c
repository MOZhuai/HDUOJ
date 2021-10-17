#include <stdio.h>
double factorial(double);
int main(){
    int n,m;
    double a[21];
    a[1] = 0;
    a[2] = 1;
    while (scanf("%d", &m) != EOF) {
        for (int i = 0; i < m; i++){
            scanf("%d", &n);
            for (int j = 3; j <= n; j++){
                a[j] = (j - 1) * (a[j - 2] + a[j - 1]);
            }
            printf("%.2lf%%\n", 100.0 * a[n] / factorial(n));
        }
    }
}
double factorial(double x){
    if(x > 1){
        return x * factorial(x - 1);
    } else {
        return 1;
    }
}