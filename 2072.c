#include <stdio.h>
#include <string.h>
int charEqual(char *s1, char *s2);
int main(){
    char s[100];
    while (gets(s)){
        char *r[100];
        if(s[0] == '#'){
            break;
        }
        const char ch[2] = " ";
        char *flag = "-";
        r[0] = strtok(s, ch);
        int i = 0;
        while (r[i++] != NULL){
            r[i] = strtok(NULL, ch);
        }
        int sum = i - 1;
        for (int j = 0; j < i - 1; j++){
            if (charEqual(r[j], flag)){
                sum--;
            }else{
                for (int k = j + 1; k < i - 1; k++){
                    if (charEqual(r[j], r[k])){
                        strcpy(r[k], "-");
                    }
                }
            }
        }
        printf("%d\n", sum);
    }
}
int charEqual(char *s1, char *s2){
    while(*s1 == *s2 && *s1){
        s1++;
        s2++;
    }
    if(!*s1 && !*s2)
        return 1;
    return 0;
}