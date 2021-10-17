#include <stdio.h>
void hexconvert(int, int);
void change(int);
int main(){
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if(n < 0){
            printf("-");
            n = -n;
        }
        hexconvert(n, m);
        printf("\n");
    }
}
void hexconvert(int n, int m){
    if(n > m){
        hexconvert(n / m, m);
        change(n % m);
    } else{
        change(n);
    }
}
void change(int x){
        switch (x){
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", x);
                break;
        }
}