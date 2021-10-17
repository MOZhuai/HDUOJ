#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n, br = 0;
    char a[2];
    while (scanf("%d %c %c", &n, &a[0], &a[1]) != EOF){
        if(br){
            printf("\n");
        } else {
            br = 1;
        }
        if(n == 1){
            printf("%c\n", a[0]);
        }else{
            int ii, flag1 = (n / 2) % 2;
            for (int i = 0; i < n; i++){
                ii = i < n / 2 ? i : n - i - 1;
                if(ii == 0){
                    printf(" ");
                    for (int j = 0; j < n - 2; j++){
                        printf("%c", a[flag1]);
                    }
                    printf(" ");
                } else {
                    int flag2 = flag1;
                    for (int j = 0; j < n; j++){
                        printf("%c", a[flag2]);
                        if (j < ii || j > (n - ii - 2)){
                            flag2 = 1 - flag2;
                        }
                    }
                }
                printf("\n");
            }
        }
    }
}