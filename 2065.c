#include <stdio.h>
long long int quickpower(long long int, long long int);
int main(){
   int T;
   while(scanf("%d",&T) != EOF){
       if(!T){
           break;
       }
       for (int i = 1; i <= T; i++){
           long long int N;
           scanf("%lld", &N);
           printf("Case %d: %lld\n", i, (quickpower(4, N - 1) + quickpower(2, N - 1)) % 100);
       }
      printf("\n");
   }
}
long long int quickpower(long long int base, long long int power){
    long long int ret = 1;
    while (power){
        if (power % 2){
            ret = ret * base % 100;
        }
        base = base * base % 100;
        power /= 2;
   }
   return ret;
}