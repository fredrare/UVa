#include <stdio.h>
int main(){
  int t,n,i=0;
  unsigned long long k;
  scanf("%i",&t);
  while(++i<=t){
    scanf("%i",&n);
    k=(unsigned long long)n*(n-1)/2;
    if(k%2)
        printf("Case %i: %llu/2\n",i,k);
    else
        printf("Case %i: %llu\n",i,k/2);
  }
  return 0;
}
