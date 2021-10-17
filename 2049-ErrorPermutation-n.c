#include <stdio.h>
long long factorial(long long);
int main(){
    int c;
    long long n, m;
    long long a[21];
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    scanf("%d", &c);
    for (int i = 0; i < c; i++){
        scanf("%lld%lld", &n, &m);
        for (int j = 3; j <= m; j++){
            a[j] = (j - 1) * (a[j - 2] + a[j - 1]);
        }
        printf("%lld\n", a[m] * (factorial(n) / (factorial(m) * factorial(n - m))));
    }
}
long long factorial(long long x){
    if(x > 1){
        return x * factorial(x - 1);
    } else {
        return 1;
    }
}