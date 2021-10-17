#include <stdio.h>
int main(){
    int n;
    long long int a[50];
    while (scanf("%d", &n) != EOF){
        a[0] = 3;
        a[1] = 6;
        a[2] = 6;
        for (int i = 3; i < n; i++){
            a[i] = a[i - 1] + a[i - 2] * 2;
        }
        printf("%lld\n", a[n - 1]);
    }
}