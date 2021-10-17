#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str1[100000], str2[100000];
void deal(char *str){
    int len;
    char *p = str;
    while(*p == '0'){
        p++;
    }
    strcpy(str, p);
    if(strchr(str, '.')){
        len = strlen(str);
        p = len + str - 1;
        while(*p == '0'){
            *p = '\0';
            p--;
        }
        if (*p == '.'){
            *p = '\0';
        }
    }
}
int main(){
    while(scanf("%s%s", str1,str2)!= EOF) {
        deal(str1);
        deal(str2);
        if (strcmp(str1, str2) == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}