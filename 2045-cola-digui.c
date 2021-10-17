#include <stdio.h>
long long int sum;
void draw(char color, int n, int cur);
int main(){
    int n;
    char fitst;
    while (scanf("%d", &n) != EOF){
        sum = 0;
        fitst = 'R';
        if(n == 1){
            sum = 1;
        } else if(n == 2) {
            sum = 2;
        } else {
            draw('P', n, 2);
            draw('G', n, 2);
        }
        sum = sum * 3;
        printf("%d\n", sum);
    }
}
void draw(char color, int n, int cur){
    switch (color) {
        case 'R':
            if(cur + 1 == n){
                sum += 2;
            } else {
                draw('P', n, cur + 1);
                draw('G', n, cur + 1);
            }
            break;
        case 'P':
            if(cur + 1 == n){
                sum += 1;
            } else {
                draw('R', n, cur + 1);
                draw('G', n, cur + 1);
            }
            break;
        case 'G':
            if(cur + 1 == n){
                sum += 1;
            } else {
                draw('R', n, cur + 1);
                draw('P', n, cur + 1);
            } 
            break;
        default:
            break;
    }
}