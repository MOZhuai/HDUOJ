#include <stdio.h>
double c(double, double);
int main(){
    int n;
    double a[26];
    a[0] = 1;
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= 25; i++){
        a[i] = (i - 1) * (a[i - 2] + a[i - 1]);
    }
    while(scanf("%d", &n) != EOF){
        if(!n){
            break;
        }
        double sum = 0;
        for (int i = (int)(1.0 * n / 2 + 0.5); i <= n; i++){
            sum += c(n, i) * a[n - i];
        }
        printf("%.lf\n", sum);
    }
}
double c(double n, double i){
    double sum = 1;
    for (int j = n; j > 0; j--){
        if(j > i && j > (n - i)){
            sum *= j;
        }
    }
    int min = i < (n - i) ? i : (n - i);
    for (int j = 1; j <= min; j++){
        sum /= j;
    }
    return sum;
}