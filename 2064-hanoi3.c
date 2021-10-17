#include <stdio.h>
#include <string.h>
long long int hanoi3(int n, int a, int b, int c);
long long int sum;
long long int memo[36][3];
// 3为3种情况
// 0. 2->1 or 2->3 -- a==2
// 1. 1->2 or 3->2 -- c==2
// 2. 1->3 or 3->1 -- .
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        memset(memo, 0, sizeof(memo));
        sum = 0;
        printf("%lld\n", hanoi3(n, 1, 2, 3));
    }
}
long long int hanoi3(int n, int a, int b, int c){
    if(n == 1){
        if(a == 2 || c == 2){
            return 1;
        } else{
            return 2;
        }
    } else {
        if(a == 2){
            if(memo[n][0] == 0){
                memo[n][0] = hanoi3(n - 1, a, c, b) + hanoi3(n - 1, b, a, c) + 1;
            }
            return memo[n][0];
        } else if(c == 2){
            if(memo[n][1] == 0){
                memo[n][1] = hanoi3(n - 1, a, c, b) + hanoi3(n - 1, b, a, c) + 1;
            }
            return memo[n][1];
        } else {
            if(memo[n][2] == 0){
                memo[n][2] = hanoi3(n - 1, a, b, c) + hanoi3(n - 1, c, b, a) + hanoi3(n - 1, a, b, c) + 2;
            }
            return memo[n][2];
        }
    }
}