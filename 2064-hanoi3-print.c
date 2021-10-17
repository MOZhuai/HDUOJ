#include <stdio.h>
void hanoi(int n, char a, char b, char c);
void hanoi3(int n, int a, int b, int c);
void hanoi3_print(int n, int a, int b, int c);
int sum;
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        sum = 0;
        hanoi3(n, 1, 2, 3);
        printf("%d\n", sum);
    }
}
void hanoi(int n, char a, char b, char c){
    if(n == 1){
        printf("%c -> %c\n", a, b);
    } else {
        hanoi(n - 1, a, c, b);
        printf("%c -> %c\n", a, b);
        hanoi(n - 1, c, b, a);
    }
}
void hanoi3(int n, int a, int b, int c){
    if(n == 1){
        if(a == 2 || c == 2){
            sum += 1;
        } else{
            sum += 2;
        }
    } else {
        if(a == 2){
            hanoi3(n - 1, a, c, b);
            sum++;
            hanoi3(n - 1, b, a, c);
        } else if(c == 2){
            hanoi3(n - 1, a, c, b);
            sum++;
            hanoi3(n - 1, b, a, c);
        } else {
            hanoi3(n - 1, a, b, c);
            sum++;
            hanoi3(n - 1, c, b, a);
            sum++;
            hanoi3(n - 1, a, b, c);
        }
    }
}
// 打印出步骤的hanoi3
void hanoi3_print(int n, int a, int b, int c){
    // 分3种情况
    // 1. 2->1 or 2->3
    // 2. 1->2 or 3->2
    // 3. 1->3 or 3->1
    if(n == 1){
        if(a == 2 || c == 2){
            printf("%d -> %d\n", a, c);
            sum++;
        } else{
            printf("%d -> %d\n", a, b);
            sum++;
            printf("%d -> %d\n", b, c);
            sum++;
        }
    } else {
        if(a == 2){
            hanoi3(n - 1, a, c, b);
            printf("%d -> %d\n", a, c);
            sum++;
            hanoi3(n - 1, b, a, c);
        } else if(c == 2){
            hanoi3(n - 1, a, c, b);
            printf("%d -> %d\n", a, c);
            sum++;
            hanoi3(n - 1, b, a, c);
        } else {
            hanoi3(n - 1, a, b, c);
            printf("%d -> %d\n", a, b);
            sum++;
            hanoi3(n - 1, c, b, a);
            printf("%d -> %d\n", b, c);
            sum++;
            hanoi3(n - 1, a, b, c);
        }
    }
}