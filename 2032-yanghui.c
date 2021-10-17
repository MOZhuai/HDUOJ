#include <stdio.h>
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[30];
        a[0] = 1;
        for (int i = 1; i < n; i++){
            a[i] = 0;
        }
        printf("1\n");
        for (int i = 1; i < n; i++){
            for (int j = i; j > 0; j--){
                a[j] = a[j] + a[j - 1];
            }
            printf("%d", a[0]);
            for (int j = 1; j < i + 1; j++){
                printf(" %d", a[j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}