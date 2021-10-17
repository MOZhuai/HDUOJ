#include <stdio.h>
#include <string.h>
long long int a[20];
int main(){
    int T;
    a[1] = 1;
    while(scanf("%d", &T) != EOF){
        int n;
        for (int i = 0; i < T; i++){
            scanf("%d", &n);
            for (int j = 1; j < n; j++){
                a[j] = 3 * a[j - 1] + 1;
            }
            printf("%lld\n", 2 * a[n - 1] + 2);
        }
    }
}