#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int main(){
    char c[1000];
    while (scanf("%s", &c) != EOF){
        if(c[0] == '#'){
            break;
        }
        char cc[1000];
        scanf("%s", &cc);
        int sum = 0;
        int length = strlen(cc);
        for (int i = 0; c[i + length - 1] != '\0'; i++){
            int j;
            for (j = 0; j < length; j++){
                if (c[i + j] != cc[j]){
                    break;
                }
            }
            if(j == length){
                sum++;
                i = i + length - 1;
            }
        }
        printf("%d\n", sum);
    }
}