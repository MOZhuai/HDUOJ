#include <stdio.h>
int main(){
    __int64 a, b;
    while(scanf("%I64X%I64X", &a, &b) != EOF){
        __int64 c = a + b;
        if (c >= 0){
            printf("%I64X\n", c);
        } else {
            printf("-%I64X\n", -c);
        }
    }
}